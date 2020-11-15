from sys import stdin, stdout
print, input = stdout.write, stdin.readline

n = int(input())
a = [int(x)-1 for x in input().split()]
b = [int(x)-1 for x in input().split()]

aind, bind = [0]*n, [0]*n
for i in range(n):
    aind[a[i]] = i
    bind[b[i]] = i

best = 999999999999999999
switch = [0]*n
good = 0
bad = 0
curr = 0
for i in range(n):
    switch[(aind[i] - bind[i])%n]+=1
    curr += abs(aind[i] - bind[i])
    if aind[i] >= bind[i]:
        good += 1
    else:
        bad += 1

for i in range(n):
    best = min(best, curr)
    good -= switch[i]
    bad += switch[i]
    curr += bad - good
    good += 1
    bad -= 1
    curr += aind[b[n-1-i]] - (n - aind[b[n-1-i]])

print(str(best))
