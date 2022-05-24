#faster io
from sys import stdin,stdout
n=int(stdin.readline())
a=stdin.readline().split()
for i in range(n):
    a[i]=int(a[i])
ans=0
for i in range(n):
    #the coordinate of the toadstool with the highest slope to toadstool i
    (xcoord,ycoord)=(0,i+1)
    for j in range(i+1,n):
        if((a[j]-a[i])*(ycoord-i)>(xcoord-a[i])*(j-i)): #slope to j is bigger
            (xcoord,ycoord)=(a[j],j)
            ans+=1 #iff the slope is higher, toadstool i can see it 
stdout.write(str(ans))
