from sys import stdin, stdout, setrecursionlimit
from math import gcd

n, j, k = (int(x) for x in stdin.readline().split())
edges = [[] for i in range(n)]
for i in range(n-1):
	u, v = (int(x) for x in stdin.readline().split())
	edges[u-1].append(v-1)


prob = [0]*n
g = 0
stack = [(0, 1, 0)]
def dfs(i):
	global g
	u, x, d = stack[i]
	prob[u] = x
	for child in edges[u]:
		stack.append((child, x/len(edges[u]), d+1))
	if len(edges[u]) == 0:
		g = gcd(g, d+1)

i = 0
while i < len(stack):
	dfs(i)
	i+=1
	
res = pow(j, k, g)
s = sum(prob)
ans = 0
stack = [(0, 0)]
def dfs2(i):
	global ans
	u, d = stack[i]
	if d%g == res:
		ans += prob[u]*g/s*d
	for child in edges[u]:
		stack.append((child, d+1))

i = 0
while i < len(stack):
	dfs2(i)
	i += 1

stdout.write(str(ans)+"\n")