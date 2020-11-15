from sys import stdin, stdout
input, print = stdin.readline, stdout.write

s = input().strip()
n = len(s)
dp = [[-1,-1] for i in range(n+1)]
dp[0] = [0, 0]

for i in range(1, n+1):
    works = False
    for x in range(10):
        if works:
            break
        for p in [2,3]:
            r = str(x**p)
            if len(r) <= i and dp[i-len(r)][1] >= 0 and ((len(r) == 1 and s[i-1] == r[0]) or (len(r)==2 and s[i-1]==r[1] and s[i-2]==r[0]) or
                (len(r) == 3 and s[i-1]==r[2] and s[i-2]==r[1] and s[i-3]==r[0])):
                dp[i] = [x, p]
                works = True
                break

if dp[n][0] == -1:
    print("-1\n")
else:
    i = n
    ans = []
    while i > 0:
        new = str(dp[i][0] ** dp[i][1])
        ans.append(str(dp[i][0]))
        i -= len(new)
    print("".join(ans[::-1])+"\n")