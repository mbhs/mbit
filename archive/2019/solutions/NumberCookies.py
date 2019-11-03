import itertools

n = int(input())
x = input().split(" ")

m = 0
for p in itertools.permutations(x):
    s = "".join(p)
    works = True
    for i in range(n-1):
        if(s[i] in ["+","*","-"] and s[i+1] in ["+","*","-"]):
            works = False
    for i in range(n-2):
        if(s[i] in ["+","*","-"] and s[i+1]=="0" and s[i+2] in [str(y) for y in range(10)]):
            works = False
    if works and s[0] not in ["0","+","*","-"] and s[-1] not in ["+","*","-"]:
        m = max(m,eval(s))

print(m)
