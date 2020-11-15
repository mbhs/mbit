from collections import defaultdict

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

aDict = defaultdict(int)
bDict = defaultdict(int)
both = defaultdict(int)
ret = n * (n - 1) // 2
for i in range(n):
    ret += both[(a[i], b[i])] - aDict[a[i]] - bDict[b[i]]
    aDict[a[i]] += 1
    bDict[b[i]] += 1
    both[(a[i], b[i])] += 1
print(ret)