def main():
    MOD = 1000000007;
    
    a = [None] * 105
    vis = [0] * 105

    change = {}
    mapUpdates = {}
    store = []
    

    n = int(input())
    a = list(map(int, input().split()))

    q = int(input())
    maxt = 0
    updates = []
    for i in range(q):
        x = input().split()
        k = int(x[0])
        t = int(x[1])
        maxt = max(maxt, t)
        updates.append(k)
        updates.append(t)

    need = []
    cur = [0] * n
    cur[0] = 1

    tmp = set()
    for i in range(q):
        tmp.add(updates[2 * i + 1])
    for i in tmp:
        need.append(i)
    need.sort()
    for i in range(len(need)):
        mapUpdates[need[i]] = i
    times = 0
    for x in need:
        while times < x:
            nxt = [None] * n
            for i in range(n):
                nxt[i] = cur[i] + cur[(i-1+n)%n]
            for i in range(n):
                if (nxt[i] >= MOD): nxt[i] -= MOD
                cur[i] = nxt[i]
            times += 1
    
        store.append(cur.copy())

    for i in range(q):
        k = updates[2 * i]
        t = mapUpdates[updates[2 * i + 1]]
        nxt = [0] * n
        use = []
        vis = [0]*n #
        
        for i in range(n):
            if vis[i]:
                continue
            v = []
            cval = i
            while (not vis[cval]):
                vis[cval] = 1
                v.append(cval)
                cval += k
                if cval >= n: cval -= n

            if len(use) == 0:
                use = [0] * len(v)
                for j in range(n):
                    idx = j % len(use)
                    use[idx] += store[t][j]
                    if use[idx] >= MOD: use[idx] -= MOD

            for j in range(len(v)):
                for l in range(len(v)):
                    idx = (j + l) % len(v)
                    nxt[v[idx]] += (use[l] * a[v[j]]) % MOD
                    nxt[v[idx]] %= MOD

        for i in range(n):
            a[i] = nxt[i]

    for i in range(n):
        print(a[i], end = " ")
    print()

main()
