from sys import stdin, stdout
from math import gcd

if __name__ == "__main__":

	n, d = (int(x) for x in stdin.readline().split())
	a = [int(x) for x in stdin.readline().split()]

	s, t = [0]*(n+1), [0]*(n+1)	#s and t are one-indexed
	for i in range(n-1, -1, -1):
		s[i] = s[i+1] + a[i]
		t[i] = t[i+1] + (i+1)*a[i]

	def cut_out(a0, a1, b0, b1, c0, c1):
		"""a = (m1, b1), b = (m2, b2), c = (m3, b3). Is the intersection of a-c before the intersection of b-c?"""
		# assert a[0] >= b[0] and b[0] >= c[0]
		return (a1-c1)*(b0-a0) <= (a1-b1)*(c0-a0)

	hulls0 = [0]*((n+1)*(n+2)//2) #[[0]*(i+2) for i in range(n+1)]
	hulls1 = [0]*((n+1)*(n+2)//2) #[[0]*(i+2) for i in range(n+1)]
	hulls0[0], hulls1[0] = 5*s[0], 2*t[0]
	it = [0]*(n+1) #current optimal hull placement
	st = [i*(i+1)//2 for i in range(n+1)]
	lh = [1] + [0]*n #length of hulls

	for i in range(1, n+1):
		for j in range(i+1):
			while(it[j] < lh[j]-1 and hulls0[st[j]+it[j]]*i+hulls1[st[j]+it[j]] >= hulls0[st[j]+it[j]+1]*i+hulls1[st[j]+it[j]+1]):
				it[j] += 1

			best = hulls0[st[j]+it[j]]*i+hulls1[st[j]+it[j]]
			if i==n and j==n:
				ans = best + 4*i*s[i] - 2*t[i]

			line = (3*s[i] + 2*s[j], best + 4*i*s[i] - 2*t[i] - 2*i*s[i] + t[i] + t[j] - i*s[j])
			while(lh[i] > 1 and cut_out(hulls0[st[i]+lh[i]-2], hulls1[st[i]+lh[i]-2],
										hulls0[st[i]+lh[i]-1], hulls1[st[i]+lh[i]-1],
										line[0], line[1])):
				lh[i] -= 1
			it[i] = min(it[i], lh[i])
			hulls0[st[i]+lh[i]], hulls1[st[i]+lh[i]] = line
			lh[i] += 1


	g = gcd(ans, d)
	stdout.write(str(ans//g) + "/" + str(d//g) + "\n")