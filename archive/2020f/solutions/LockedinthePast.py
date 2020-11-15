from sys import stdin, stdout
input, print = stdin.readline, stdout.write

inp = input().split()
n, k = int(inp[0]), int(inp[1])+1

a = [int(x) for x in input().split()]

neg = [0]*(n+1)
pos = [0]*(n+1)
for i in range(n+1):
    neg[i] = i*k
    pos[i] = i*k

#print(pos, neg)
bef = 0
for i in range(n):
    nneg = [0]*(n+1)
    npos = [0]*(n+1)

    if a[i] >= bef:
        bb = min(min(pos), min(neg[1:]))
        best = bb
        for j in range(n+1):
            best = min(best, pos[j]-(bef + j*k))
            npos[j] = a[i]+j*k + best
        best = bb
        for j in range(1, n+1):
            nneg[j] = -a[i]+j*k + best
            best = min(best, neg[j]-(j*k - bef))

        best = pos[n]
        for j in range(n-1, -1, -1):
            npos[j] = min(npos[j], best)
            best = min(best, pos[j])
        best = neg[n]
        for j in range(n, 0, -1):
            best = min(best, neg[j])
            nneg[j] = min(nneg[j], best)
            

    else:
        bb = min(min(pos), min(neg[1:]))
        best = bb
        for j in range(n+1):
            npos[j] = a[i]+j*k + best
            best = min(best, pos[j]-(bef + j*k))
        best = bb
        for j in range(1, n+1):
            best = min(best, neg[j]-(j*k - bef))
            nneg[j] = -a[i]+j*k + best
        best = pos[j]
        for j in range(n, -1, -1):
            best = min(best, pos[j])
            npos[j] = min(npos[j], best)
            

        best = neg[n]
        for j in range(n-1, 0, -1):
            nneg[j] = min(nneg[j], best)
            best = min(best, neg[j])
            
    pos = npos
    neg = nneg
    bef = a[i]
    #print(i, pos)
    #print(neg)
    

print(str(min(min(pos), min(neg[1:]))))
