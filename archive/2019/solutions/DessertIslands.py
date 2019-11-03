n, m = [int(i) for i in input().split()]
graph = []
for i in range(n):
    graph.append(input())

numIsland = 0
numLake = 0
visited = [[False for i in range(m)] for j in range(n)]
for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            if graph[i][j] == 'S':
                numIsland += 1
            else:
                numLake += 1
            visited[i][j] = True
            q = [(i, j)]
            while q:
                x = q[0][0]
                y = q[0][1]
                q.pop(0)

                if x > 0 and not visited[x-1][y] and graph[x-1][y] == graph[i][j]:
                    visited[x-1][y] = True
                    q.append((x-1, y))
                if x < n - 1 and not visited[x+1][y] and graph[x+1][y] == graph[i][j]:
                    visited[x+1][y] = True
                    q.append((x+1, y))
                if y > 0 and not visited[x][y-1] and graph[x][y-1] == graph[i][j]:
                    visited[x][y-1] = True
                    q.append((x, y-1))
                if y < m - 1 and not visited[x][y+1] and graph[x][y+1] == graph[i][j]:
                    visited[x][y+1] = True
                    q.append((x, y+1))

print(numIsland - 1, numLake)