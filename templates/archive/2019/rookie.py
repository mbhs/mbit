f=lambda:input().split()
i=int
n,q=f()
l=[0]*i(n)
m=[*map(i,f())]
for _ in [0]*i(q):
a,b,*c=f();b=i(b)-1
if a=='FILL':l[b]=m[b]
if a=='POUR':
c=i(c[0])-1;d=m[c]-l[c]
if l[b]<d:l[c]+=l[b];l[b]=0
else:l[b]-=d;l[c]+=d
if a=='EMPTY':l[b]=0
print(*l)