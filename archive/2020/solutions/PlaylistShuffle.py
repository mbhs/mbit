line = input().split()
n = int(line[0])
b = int(line[1])
x = int(line[2])
y = int(line[3])
b -= 1

lo = 0
hi = n
while lo < hi:
    dist = (lo+hi+1)//2
    left, right = min(b, dist), min(n-1-b, dist)
    s = x*(left*(left+1)//2 + right*(right+1)//2)
    assigned = left + right + 1
    ifrand = (y*n+s)/assigned #Quite a bit of algebra is hidden in this step.

    if ifrand <= x*dist:
        hi = dist-1
    else:
        lo = dist

dist = lo
#print(dist)
left, right = min(b, dist), min(n-1-b, dist)
s = x*(left*(left+1)//2 + right*(right+1)//2)
assigned = left + right + 1
ifrand = (y*n+s)/assigned #Quite a bit of algebra is hidden in this step.

print(ifrand - y)

