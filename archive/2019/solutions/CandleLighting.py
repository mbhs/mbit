s = input().split(" ")
n = int(s[0])
m = int(s[1])

a = []
prefixSum = []
for i in range(n):
    a.append([int(x) for x in input().split(" ")])
    prefixSum.append([0 for x in range(m+1)])
prefixSum.append([0 for x in range(m+1)])

q = int(input())
for i in range(q):
    s = input().split(" ")
    x1 = int(s[0])-1
    y1 = int(s[1])-1
    x2 = int(s[2])-1
    y2 = int(s[3])-1
    prefixSum[x1][y1]+=1
    prefixSum[x1][y2+1]-=1
    prefixSum[x2+1][y1]-=1
    prefixSum[x2+1][y2+1]+=1

tot = 0
for i in range(n):
    for j in range(m):
        if (i > 0):
            prefixSum[i][j] += prefixSum[i-1][j]
        if (j > 0):
            prefixSum[i][j] += prefixSum[i][j-1]
        if (i > 0 and j > 0):
            prefixSum[i][j] -= prefixSum[i-1][j-1]
        tot += (a[i][j] + prefixSum[i][j]) % 2

print(tot)