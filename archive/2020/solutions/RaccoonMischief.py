from heapq import *

n, q = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

add = [[] for i in range(n)]
rem = [[] for i in range(n)]
for i in range(q):
    l, r, x = [int(_) for _ in input().split()]
    add[l-1].append((i, x))
    rem[r-1].append((i, x))

inQueue = [True] * q
pq = []
sz = 0
for i in range(n):
    for p in add[i]:
        heappush(pq, (-p[0], p[1]))
        sz += 1

    if pq:
        if (sz % 2 == 0) != (a[i] == 0):
            print(pq[0][1], end=' ')
        else:
            print(0, end=' ')
    else:
        print(a[i], end=' ')

    for p in rem[i]:
        inQueue[p[0]] = False
        sz -= 1

    while pq and not inQueue[-pq[0][0]]:
        heappop(pq)
