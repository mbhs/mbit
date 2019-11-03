class Vertex:
    def __init__(self):
        self.adj = []
    def addEdge(self, v, wt):
        self.adj.append((v, wt))

n, m, c = [int(i) for i in input().split()]
a, b = [int(i)-1 for i in input().split()]
p = [int(i) for i in input().split()]

graph = [Vertex() for i in range(n)]
for i in range(m):
    x, y, z = [int(i) for i in input().split()]
    graph[x-1].addEdge(y-1, z)
    graph[y-1].addEdge(x-1, z)

visited = [[False for i in range(c+1)] for j in range(n)]
q = [(a, 0, 0)]
while q:
    node, fuel, dist = q[0]
    q.pop(0)

    if fuel > c:
        fuel = c
    if fuel < 0 or visited[node][fuel]:
        continue
    if node == b:
        print(dist)
        break

    visited[node][fuel] = True
    q.append((node, fuel + p[node], dist + 1))
    for e in graph[node].adj:
        q.append((e[0], fuel - e[1], dist + 1))
