def main():
    a = []
    dp = []
    pre = []
    preSquare = []
    def get(x, y):
        if x > y:
            x, y = y, x
        res = preSquare[y] - (0 if x == 0 else preSquare[x-1])
        s = pre[y] - (0 if x == 0 else pre[x-1])
        return res - 2*s*s/(y - x + 1) + s * s/(y - x + 1)
    inp = input().split()
    n = int(inp[0])
    k = int(inp[1])
    if(k == 0):
        return 0
    stin = input().split()
    for i in range(n):
        a.append(int(stin[i]))
    for i in range(n):
        if i == 0:
            preSquare.append(a[i] * a[i])
            pre.append(a[i])
        else:
            preSquare.append(preSquare[i-1] + a[i] * a[i])
            pre.append(pre[i-1] + a[i])
        dp.append(float('inf'))
    for i in range(n):
        if i >= k - 1:
            dp[i] = get(0, i)
        for j in range(i - k + 1):
            dp[i] = min(dp[i], dp[j] + get(j+1, i))

    return dp[n-1]

print(int(main()))
