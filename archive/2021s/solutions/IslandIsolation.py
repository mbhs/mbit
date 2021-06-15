from sys import stdin, stdout
input, print = stdin.readline, stdout.write

def main():
    n = int(input())
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = [int(i) - 1 for i in input().split()]
        adj[u].append(v)
        adj[v].append(u)

    depth = [-1] * n
    depth[0] = 0
    stk = [0]
    edges = [[] for _ in range(n)]
    while stk:
        u = stk.pop()
        for v in adj[u]:
            if depth[v] == -1:
                depth[v] = depth[u] + 1
                stk.append(v)
                edges[depth[v]].append((u, v))
    for d in range(n - 1, 0, -1):
        for u, v in edges[d]:
            print(str(u + 1) + ' ' + str(v + 1) + '\n')

    depth = [-1] * n
    depth[0] = 0
    stk = [0]
    edges = [[] for _ in range(n)]
    while stk:
        u = stk.pop()
        for v in adj[u]:
            if depth[v] == -1:
                depth[v] = depth[u] + 1
                stk.append(v)
                edges[depth[v]].append((u, v))
    for d in range(1, n):
        for u, v in edges[d]:
            print(str(v + 1) + ' ' + str(u + 1) + '\n')

main()