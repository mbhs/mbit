#faster io
from sys import stdin,stdout
n=int(stdin.readline())
l=stdin.readline().split()
#nextbest[i] represents the lexicographic least unused string of length i
#must use nested lists because strings are immutable
nextbest=[[]]*5001
for i in range(1,5001):
    nextbest[i]=['a']*i #they all start as all a's
for i in range(n):
    length=int(l[i])
    for i in range(length): #output string represented by nextbest[length]
        stdout.write(nextbest[length][i])
    stdout.write(" ")
    #update nextbest[length] to the next lexicographic string
    for j in range(length-1,-1,-1):
        if(nextbest[length][j]=='z'): #set all trailing 'z's to be 'a'
            nextbest[length][j]='a';
        else: #increment the first non-z letter from back
            nextbest[length][j]=chr(ord(nextbest[length][j])+1)
            break;
