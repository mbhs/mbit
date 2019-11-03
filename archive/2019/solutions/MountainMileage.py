n, a, b = [int(i) for i in input().split()]
m = [int(i) for i in input().split()]

m.sort()
meet = m[n * b // (a + b)]

ret = 0
for i in m:
    if i < meet:
        ret += a * (meet - i)
    else:
        ret += b * (i - meet)

print(ret)
