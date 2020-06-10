from collections import deque

class Point:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.y > other.y

INF = 1000000000

n, z, k = input().split()
n = int(n)
z = int(z)
k = float(k)

p = []
for i in range(n):
    x, y = [int(i) for i in input().split()]
    p.append(Point(x, y))
p.sort()

dp = [INF] * n * (z + 1)
dp[p[0].x] = 0
for i in range(1, n):
    dq = deque()
    ptr1 = ptr2 = 0
    for j in range(z + 1):
        l = max(j - int((p[i-1].y - p[i].y) / k), 0)
        r = min(j + int((p[i-1].y - p[i].y) / k), z)
        while ptr2 < l:
            if dq[0][1] == ptr2:
                dq.popleft()
            ptr2 += 1
        while ptr1 <= r:
            while dq and dp[(i-1) * (z+1) + ptr1] <= dq[-1][0]:
                dq.pop()
            dq.append((dp[(i-1) * (z+1) + ptr1], ptr1))
            ptr1 += 1
        dp[i * (z+1) + j] = dq[0][0] + abs(j - p[i].x)

print(dp[(n-1) * (z+1) + p[n-1].x])
