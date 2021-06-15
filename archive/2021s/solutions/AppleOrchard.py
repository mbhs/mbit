from sys import stdin, stdout


n, m, x, y, a, b, c, d = (int(x) for x in stdin.readline().split())

def ans(n, m):
	global a, b, x, y
	return max(0, a-n)*x + max(0, b-m)*y

best = 10**10
for trade in range(-20000, 20000):
	best = min(best, ans(n-c*trade, m+d*trade))

stdout.write(str(best) + "\n")