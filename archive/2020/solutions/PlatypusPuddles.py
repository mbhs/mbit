from heapq import heappush, heappop
from sys import stdin
def main():
    n = int(input())

    grid = []
    visited = []
    for i in range(n):
        visited.extend([False]*n)
        grid.extend([int(x) for x in stdin.readline().split()])

    ans = 0

    pq = []
    for i in range(n):
        if i==0 or i==n-1:
            for j in range(n):
                heappush(pq, (grid[i*n+j], i, j))
        else:
            heappush(pq, (grid[i*n+0], i, 0))
            heappush(pq, (grid[i*n+n-1], i, n-1))

    while(len(pq) > 0):
        val, i, j = heappop(pq)
        if(visited[i*n+j]):
            continue
        visited[i*n+j] = True
        ans += max(0, val-grid[i*n+j])
        newval = max(grid[i*n+j], val)
        if i>0:
            heappush(pq, (newval, i-1, j))

        if i<n-1:
            heappush(pq, (newval, i+1, j))

        if j>0:
            heappush(pq, (newval, i, j-1))

        if j<n-1:
            heappush(pq, (newval, i, j+1))

    print(ans)

main()
