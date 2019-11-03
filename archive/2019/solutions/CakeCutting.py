from queue import PriorityQueue

def main():
    MAX = 100005
    LOG = 20

    adj = []
    routes = []

    depth = [None] * MAX
    par = [None] * MAX * LOG
    
    def dfs(cur, prev):
        par[cur * LOG] = prev
        for nxt in adj[cur]:
            if (nxt == prev):
                continue
            depth[nxt] = depth[cur] + 1
            dfs(nxt, cur)

    def process():
        depth[0] = 0
        dfs(0, 0)
        for lvl in range(LOG - 1):
            for cur in range(n):
                mid = par[cur * LOG + lvl]
                par[cur * LOG + lvl + 1] = par[mid * LOG + lvl]

    def above(u, k):
        for it in range(LOG - 1, -1, -1):
            if(k >= (1 << it)):
                u = par[u * LOG + it]
                k -= (1<<it)
        return u

    def get_ancestor(top, bot):
        if(depth[top] >= depth[bot]):
            return par[top * LOG]
        anc = above(bot, depth[bot] - depth[top] - 1)
        if(par[anc * LOG] == top):
            return anc
        return par[top * LOG]

    inp = input().split()
    n = int(inp[0])
    m = int(inp[1])
    k = int(inp[2])
    
    for i in range(MAX):
        adj.append([])
        routes.append([])
    
    for i in range(n-1):
        inp = input().split()
        u = int(inp[0]) - 1
        v = int(inp[1]) - 1
        adj[u].append(v)
        adj[v].append(u)

    for i in range(m):
        inp = input().split()
        u = int(inp[0]) - 1
        v = int(inp[1]) - 1
        w = int(inp[2])

        routes[u].append([v, w])
        routes[v].append([u, w])

    process()

    ans = float('inf')

    for i in range(n):
      sub = {}
      if (len(routes[i]) < k):
          continue
      for j in range(len(routes[i])):
        try:
          sub[get_ancestor(i, routes[i][j][0])].put(routes[i][j][1])
        except KeyError:
          anc = get_ancestor(i, routes[i][j][0])
          sub[anc] = PriorityQueue()
          sub[anc].put(routes[i][j][1])
      for key in sub:
        x = sub[key]
        if(x.qsize() >= k):
          val = 0
          for j in range(k):
            elm = x.get()
            val += elm
          ans = min(ans, val)
    if(ans == float("inf")):
      print(-1)
    else:
      print(ans)

main()