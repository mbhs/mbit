n, f = [int(i) for i in input().split()]
a = [int(i)-1 for i in input().split()]

flavor = [0] * f
i = 0
mx = 0
cnt = 0
bestL = 0
bestR = 0
for j in range(n):
    if flavor[a[j]] == 0:
        cnt += 1
    flavor[a[j]] += 1
    while flavor[a[i]] > 1:
        flavor[a[i]] -= 1
        i += 1
    if cnt == f and i + n - 1 - j > mx:
        mx = i + n - 1 - j
        bestL = i
        bestR = n - 1 - j

print(bestL, bestR)