from sys import stdin, stdout

s = stdin.readline().strip()
n = len(s)

dp = [0]*n
let = [999999999]*26

let[ord(s[0])-ord('a')] = 0
dp[0] = 1

for i in range(1, len(s)):
    x = ord(s[i]) - ord('a')
    let[x] = min(let[x], dp[i-1])
    dp[i] = let[x] + 1

stdout.write(str(dp[n-1]))
