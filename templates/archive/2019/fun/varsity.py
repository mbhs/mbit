f=lambda:input().split()
j=int
n,q=map(j,f())
c=list(map(j,f()))
x=[0]*n
while q>0:
q-=1
s=f()
t=s[0][0]
a=j(s[1])-1
if t>"O":b=j(s[2])-1;d=min(x[a],c[b]-x[b]);x[b]+=d;x[a]-=d
else:x[a]=0if t<"F"else c[a]
print(" ".join(map(str,x)))