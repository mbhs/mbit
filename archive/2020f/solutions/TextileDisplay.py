from sys import stdin, stdout

MOD = 10**9 + 7

def mpow(base, exp):
    res = 1
    while(exp):
        if exp%2 == 1:
            res = (res*base)%MOD
        exp //=2
        base = (base*base)%MOD
    return res

inp = stdin.readline().split()
n, m = int(inp[0]), int(inp[1])

fac = [1]*(n+1)
#invfac = [1]*(n+1)
for i in range(1, n+1):
    fac[i] = (fac[i-1]*i)%MOD
#invfac[n] = mpow(fac[n], MOD-2)
#for i in range(n-1, -1, -1):
#    invfac[i] = (invfac[i+1]*(i+1))%MOD

def choose(a, b):
    if b>a:
        return 0
    return (((fac[a]*mpow(fac[b], MOD-2))%MOD)*mpow(fac[a-b], MOD-2))%MOD

def comp(k):
    return ((((n*choose(n, k) - choose(n, k+1))%MOD)*fac[k])*fac[n-k])%MOD
ans = 0
for x in stdin.readline().split():
    ans += comp(int(x))
stdout.write(str(ans%MOD))#sum([comp(int(x)) for x in stdin.readline().split()]) % MOD))
    