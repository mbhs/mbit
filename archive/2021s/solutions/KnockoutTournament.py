from sys import stdin, stdout

MOD = 10**9 + 7
MAXN = 132000

def minv(x):
	return pow(x, MOD-2, MOD)

def choose(a, b):
	if b > a: return 0
	return (((fac[a]*ifac[b])%MOD)*ifac[a-b])%MOD

def ichoose(a, b):
	if b > a: return 0
	return (((ifac[a]*fac[b])%MOD)*fac[a-b])%MOD

fac = [1]
ifac = [1]
for i in range(MAXN):
	fac.append((fac[i] * (i+1))%MOD)
for i in range(MAXN):
	ifac.append(minv(fac[i+1]))

n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]
a.sort()

p2 = [2**i for i in range(n+1)]
ans = a[p2[n]-1]
for i in range(p2[n]):
	pwin = [(choose(i, p2[j]-1)*ichoose(p2[n]-1, p2[j]-1))%MOD for j in range(1, n+1)]
	ans = (ans + (sum(pwin) - 1)*a[i])%MOD

ans = (ans + MOD)%MOD
stdout.write(str(ans))