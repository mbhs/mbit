#faster io
from sys import stdin,stdout
n=int(stdin.readline())
a=stdin.readline().split()
for i in range(n):
    a[i]=int(a[i])
big=0 #big is the biggest a[i]-i
for i in range(n):
    big=max(big,a[i]-i)
ans=0
for i in range(n):
    ans=max(ans,big-(a[i]-i))
stdout.write(str(ans))
