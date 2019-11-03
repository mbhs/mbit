MOD = 1000000007

n = int(input())

numPaths = [0] * n * n
dp = [0] * n * n * n

numPaths[0] = 1
for i in range(n):
    a = [int(i)-1 for i in input().split()]
    for j in range(n):
        if i > 0:
            numPaths[n*i+j] = (numPaths[n*i+j] + numPaths[n*(i-1)+j]) % MOD
        if j > 0:
            numPaths[n*i+j] = (numPaths[n*i+j] + numPaths[n*i+j-1]) % MOD
        for k in range(n):
            if a[j] == k:
                dp[n*n*i+n*j+k] = numPaths[n*i+j]
            else:
                if i > 0:
                    dp[n*n*i+n*j+k] = (dp[n*n*i+n*j+k] + dp[n*n*(i-1)+n*j+k]) % MOD
                if j > 0:
                    dp[n*n*i+n*j+k] = (dp[n*n*i+n*j+k] + dp[n*n*i+n*(j-1)+k]) % MOD

for i in range(n):
    print(i+1, dp[n*n*(n-1)+n*(n-1)+i])