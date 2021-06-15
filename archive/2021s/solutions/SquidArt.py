from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(100000)

class DSU:
    def __init__(self,m):
        self.count=m
        self.parent=[i for i in range(m)]
        self.size=[1 for _ in range(m)]

    def root(self,A):
        while self.parent[A] != A:
            prev = A
            A = self.parent[A]
            self.parent[prev] = self.parent[A]
        return A

    def join(self,A,B):
        C=self.root(A)
        D=self.root(B)
        if C==D:
            return
        
        if self.size[C] < self.size[D]:
            self.parent[C]=D
            self.size[D] += self.size[C]

        else:
            self.parent[D] = C
            self.size[C] += self.size[D]
            
        self.count-=1

    def together(self,A,B):
        return self.root(A) == self.root(B)

n, m = (int(x) for x in stdin.readline().split())

a = "".join([stdin.readline().strip() for i in range(n)])
d = DSU(n*m)
for i in range(n):
    for j in range(m):
        if j < m-1:
            if a[i*m+j] == a[i*m+j+1]:  #horizontal adj
                d.join(i*m+j, i*m+j+1)
        if i < n-1:
            if a[i*m+j] == a[(i+1)*m+j]:
                d.join(i*m+j, (i+1)*m+j)
            if i%2 == 0:
                if j < m-1 and a[i*m+j] == a[(i+1)*m+j+1]:
                    d.join(i*m+j, (i+1)*m+j+1)
            else:
                if j > 0 and a[i*m+j] == a[(i+1)*m+j-1]:
                    d.join(i*m+j, (i+1)*m+j-1)

x = d.count
root = [d.root(i) for i in range(n*m)]
edges = [[] for i in range(n*m)]
for i in range(n):
    for j in range(m):
        if j < m-1:
            if a[i*m+j] != a[i*m+j+1] and not d.together(i*m+j, i*m+j+1):  #horizontal adj
                edges[root[i*m+j]].append(root[i*m+j+1])
                edges[root[i*m+j+1]].append(root[i*m+j])
                d.join(i*m+j, i*m+j+1)
        if i < n-1:
            if a[i*m+j] != a[(i+1)*m+j] and not d.together(i*m+j, (i+1)*m+j):
                edges[root[i*m+j]].append(root[(i+1)*m+j])
                edges[root[(i+1)*m+j]].append(root[i*m+j])
                d.join(i*m+j, (i+1)*m+j)
            if i%2 == 0:
                if j < m-1 and a[i*m+j] != a[(i+1)*m+j+1] and not d.together(i*m+j, (i+1)*m+j+1):
                    edges[root[i*m+j]].append(root[(i+1)*m+j+1])
                    edges[root[(i+1)*m+j+1]].append(root[i*m+j])
                    d.join(i*m+j, (i+1)*m+j+1)
            else:
                if j > 0 and a[i*m+j] != a[(i+1)*m+j-1] and not d.together(i*m+j, (i+1)*m+j-1):
                    edges[root[i*m+j]].append(root[(i+1)*m+j-1])
                    edges[root[(i+1)*m+j-1]].append(root[i*m+j])
                    d.join(i*m+j, (i+1)*m+j-1)

def dfs(u, par):
    """Returns the pair (distance, farthest node)"""
    best = (0, u)
    for oth in edges[u]:
        if(oth != par):
            x = dfs(oth, u)
            best = max(best, (x[0]+1, x[1]))
    return best

far = dfs(root[0], -1)[1]
dist = dfs(far, -1)[0]

if dist%2 == 1:
    stdout.write(str((dist+1)//2))
else:
    if a[far] == "1":
        stdout.write(str(dist//2))
    else:
        stdout.write(str(dist//2+1))
