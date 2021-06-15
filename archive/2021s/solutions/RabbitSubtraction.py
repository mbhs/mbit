from sys import stdin, stdout


n = int(stdin.readline())
a = [int(x) for x in stdin.readline().split()]

x = 1
while 2**x <= n:
    x+=1
p2 = [2**i for i in range(x+5)]

dp = [[0]*x for i in range(n)]
for i in range(n):
    dp[i][0] = a[i]

for t in range(x-1):
    for i in range(n):
        dp[i][t+1] = dp[i][t] - dp[(i+p2[t])%n][t]

best = -1e9 #I think we can prove the answer is always non-negative
startsign = 1 if bin(n).count("1")%2 == 1 else -1
for i in range(n):
    sign = startsign
    curr = 0
    k = n
    t = 0
    iadd = n
    while k > 0:
        if k%2 == 1:
            iadd -= p2[t]
            curr += sign*dp[(i+iadd)%n][t]
            sign *= -1
        t += 1
        k >>= 1
    best = max(best, curr)
    #print(i, curr)

stdout.write(str(best))
