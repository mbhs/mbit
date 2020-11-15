from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(10000)

n = int(stdin.readline())
red = [x=="1" for x in stdin.readline()]

adj = [[] for i in range(n)]
for i in range(n-1):
    inp = stdin.readline().split()
    a, b = int(inp[0])-1, int(inp[1])-1
    adj[a].append(b)
    adj[b].append(a)

up = [[0]*(n+1) for i in range(n)]
down = [[0]*(n+1) for i in range(n)]

def dfs(u, par):
    for child in adj[u]:
        if child != par:
            dfs(child, u)
            
    if red[u]:
        for k in range(n):
            up[u][k]= k
            down[u][k] = k
            for child in adj[u]:
                if child != par:
                    up[u][k] += max(up[child][k+1], down[child][1])
                    down[u][k] += max(up[child][1], down[child][k+1])
    else:
        for k in range(n):
            up[u][k]= k
            down[u][k] = 0
            for child in adj[u]:
                if child != par:
                    up[u][k] += max(up[child][k], down[child][1])
                    down[u][k] += max(up[child][0], down[child][k+1])

dfs(0, -1)
stdout.write(str(up[0][0]))
