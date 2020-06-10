from collections import deque

n = int(input())
a = [int(i) for i in input().split()]

dist = [-1 for i in range(n)]
q = deque([0])
dist[0] = 0
while q:
    u = q.popleft()
    d = 0
    h = 0
    for v in range(u + 1, n):
        if (a[v] - a[u]) * d >= h * (v - u):
            d = v - u
            h = a[v] - a[u]
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)

print(dist[n-1]+1)
