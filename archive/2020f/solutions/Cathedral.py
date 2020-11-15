from sys import stdin, stdout
print, input = stdout.write, stdin.readline

inp = input().split()
n, m = int(inp[0]), int(inp[1])

a = [int(x) for x in input().split()]
p = [0]*(n)
p[0] = a[0]

for i in range(1, n):
    p[i] = p[i-1] + a[i]

for mi in range(m):
    inp = input().split()
    s, k = int(inp[0])-1, int(inp[1])

    tot = p[s+2*k-1] - (p[s-1] if s>0 else 0)
    lo = s
    hi = s+k
    while hi - lo > 1:
        mid = (lo + hi)//2
        val = p[mid+k-1] - (p[mid-1] if mid>0 else 0)
        if val >= tot/2:
            lo = mid
        else:
            hi = mid

    ans = min(abs(tot- 2*(p[lo+k-1] - (p[lo-1] if lo>0 else 0))),
              abs(tot- 2*(p[hi+k-1] - (p[hi-1] if hi>0 else 0))))

    print(str(ans) + "\n")
