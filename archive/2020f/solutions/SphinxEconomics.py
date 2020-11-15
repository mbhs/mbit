if __name__ == "__main__":
    MOD = 10**9 + 7
    
    inp = input().split()
    n, q = int(inp[0]), int(inp[1])
    
    dp = [1]*(n+1)
    s = 1
    
    #{q-1}-fibonacci sequence
    for i in range(1, n+1):
        dp[i] = s
        s += dp[i]
        if i >= q-1:
            s -= dp[i-(q-1)]
        s %= MOD
    
    print((pow(dp[n], MOD-2, mod=MOD)*pow(2, n-1, mod=MOD))%MOD)
