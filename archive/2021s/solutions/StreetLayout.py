n, m, l = map(int, input().split())
a = sorted(list(map(int, input().split())))
lo = 1
hi = l
while lo < hi:
    mid = (lo + hi) // 2
    cnt = min(a[0] - 1, mid) + min(l - a[n-1], mid)
    for i in range(1, n):
        cnt += min(a[i] - a[i-1] - 1, 2 * mid)
    if cnt >= m:
        hi = mid
    else:
        lo = mid + 1
print(lo)