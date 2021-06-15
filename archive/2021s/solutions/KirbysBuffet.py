from sys import stdin, stdout

n, q = (int(x) for x in stdin.readline().split())
a = [int(x) for x in stdin.readline().split()]


b = 1700	#bucket size
null = (1<<18) - 1
amax = 1 << 17
bkts = 	[[null]*amax for i in range(0, n, b)]

for i in range(n):
	bkts[i//b][a[i]] = a[i]

for buck in bkts:
	for x in range(amax-1, -1, -1):
		for i in range(17):
			buck[x] &= buck[x|(1<<i)]

for qi in range(q):
	l, r, x = (int(x) for x in stdin.readline().split())
	curr = null
	p = l-1
	while p < r and p%b > 0:
		if a[p] & x == x:
			curr &= a[p]
		p += 1
	while p+b <= r:
		curr &= bkts[p//b][x]
		p += b
	while p < r:
		if a[p] & x == x:
			curr &= a[p]
		p += 1

	stdout.write("YES\n" if curr==x else "NO\n")