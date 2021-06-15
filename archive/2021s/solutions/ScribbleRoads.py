from sys import stdin, stdout

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


t = int(stdin.readline())

ans = {}
def solve(x, y, d):
	if (x, y, d) in ans:
		return ans[(x, y, d)]
	if x + y == 1:
		ans[(x, y, d)] = False
	elif x+y == 2:
		ans[(x, y, d)] = True
	else:
		bad = True
		if x >= 2:
			bad &= solve(x-2, y+1, d)
		if y >= 1:
			bad &= solve(x, y-1, 1-d)
		if d == 1:
			bad &= solve(x, y, 0)
		ans[(x, y, d)] = not bad
	return ans[(x, y, d)]

for ti in range(t):
	n, m = (int(x) for x in stdin.readline().split())
	edges = [[] for i in range(n)]
	dsu = DSU(n)
	for i in range(m):
		u, v = (int(x) for x in stdin.readline().split())
		dsu.join(u-1, v-1)

	x = 0
	y = 0
	d = 0
	for i in range(n):
		if i == dsu.parent[i]:
			sz = dsu.size[i]
			if sz%2 == 1:
				x += 1
			else:
				y += 1
			d += sz*(sz-1)//2
	d -= m
	d %= 2
	if x < 10 and y < 10:
		win = solve(x, y, d)
	else:
		if d == 0:
			if y < 2:
				win = (x%4 in [0, 3])
			elif y == 2:
				win = (x%4 in [0, 2, 3])
			else:
				win = (x%4 in [2, 3])
		else:
			if y < 2:
				win = (x%4 in [1, 2])
			elif y == 2:
				win = (x%4 in [0, 1, 2])
			else:
				win = (x%4 in [0, 1])

	if win:
		stdout.write("WIN\n")
	else:
		stdout.write("LOSE\n")