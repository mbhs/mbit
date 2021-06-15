from sys import stdin, stdout


n, k = (int(x) for x in stdin.readline().split())
orig = [[int(x) for x in stdin.readline().split()] for i in range(n)]
grid = [[0]*n for i in range(n)]
m = [0]*(n*n+1)
it = 1

for i in range(n):
	for j in range(n):
		if orig[i][j] > 0:
			grid[i][j] = it
			m[it] = orig[i][j]
			it += 1

def up():
	global grid
	new = [[0]*n for i in range(n)]
	for i in range(n):
		it = 0
		for j in range(n):
			if grid[j][i] > 0:
				new[it][i] = grid[j][i]
				it += 1
	grid = new

def down():
	global grid
	new = [[0]*n for i in range(n)]
	for i in range(n):
		it = n-1
		for j in range(n-1, -1, -1):
			if grid[j][i] > 0:
				new[it][i] = grid[j][i]
				it -= 1
	grid = new

def left():
	global grid
	new = [[0]*n for i in range(n)]
	for i in range(n):
		it = 0
		for j in range(n):
			if grid[i][j] > 0:
				new[i][it] = grid[i][j]
				it += 1
	grid = new

def right():
	global grid
	new = [[0]*n for i in range(n)]
	for i in range(n):
		it = n-1
		for j in range(n-1, -1, -1):
			if grid[i][j] > 0:
				new[i][it] = grid[i][j]
				it -= 1
	grid = new

if k <= 4:
	down()
	if k > 1:
		right()
	if k > 2:
		up()
	if k > 3:
		left()

	for i in range(n):
		stdout.write(" ".join([str(m[x]) for x in grid[i]]) + "\n")

else:
	down()
	right()
	up()
	left()
	k -= 4
	before = [row[:] for row in grid]
	down()
	right()
	up()
	left()

	perm = [0]*it
	for i in range(n):
		for j in range(n):
			if grid[i][j] > 0:
				perm[before[i][j]] = grid[i][j]
	assert perm[0] == 0

	ans = [0]*it
	for i in range(1, it):
		if ans[i] > 0:
			continue
		cycle = [i]
		curr = perm[i]
		while curr != i:
			cycle.append(curr)
			curr = perm[curr]
		p = (k//4)%len(cycle)
		for x in range(len(cycle)):
			ans[cycle[x]] = cycle[p]
			p = (p+1)%len(cycle)

	for i in range(n):
		for j in range(n):
			grid[i][j] = ans[before[i][j]]
	k %= 4
	
	if k > 0:
		down()
	if k > 1:
		right()
	if k > 2:
		up()
	if k > 3:
		left()

	for i in range(n):
		stdout.write(" ".join([str(m[x]) for x in grid[i]]) + "\n")