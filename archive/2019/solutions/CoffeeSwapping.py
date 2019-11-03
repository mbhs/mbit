n = int(input())
a = [int(i) for i in input().split()]
b = [[]] * 2 * n
for i in range(2*n):
    b[i] = [a[i], i]

b.sort()
mp = {}
for i in range(2*n):
    mp[b[i][0]] = i

ret = 0
for i in range(n):
    pos = 2 * n - mp[a[2*i]] - 1
    if b[pos][1] != 2 * i + 1:
        ret += 1
        tmp = a[2*i+1]
        a[b[pos][1]], a[2*i+1] = a[2*i+1], a[b[pos][1]]
        b[mp[tmp]][1], b[pos][1] = b[pos][1], b[mp[tmp]][1]

print(ret)
