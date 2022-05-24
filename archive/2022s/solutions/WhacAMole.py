#faster io
from sys import stdin,stdout
[n,q]=stdin.readline().split()
n=int(n)
q=int(q)
#a represents the current state of moles
a=[1]*n
#curr is the number of moles currently up
curr=n
x=stdin.readline().split()
ends=False
for i in range(q):
    hole=int(x[i])-1
    if(a[hole]==1): #selected mole was up
        a[hole]=0
        curr-=1
    else: #selected mole was down
        a[hole]=1
        curr+=1
    if(curr==0): #game finished
        ends=True
        stdout.write(str(i+1))
        break
if(not(ends)): #if the game never ended
    stdout.write("-1")
