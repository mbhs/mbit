n, q = [int(i) for i in input().split()]
pref = [int(i) for i in input().split()]

for i in range(1, n):
    pref[i] += pref[i-1]

for i in range(q):
    u, v = [int(_) - 1 for _ in input().split()]
    if u > v:
        u, v = v, u

    tot = pref[v-1] - (pref[u-1] if u > 0 else 0)
    print(min(tot, pref[n-1] - tot))
