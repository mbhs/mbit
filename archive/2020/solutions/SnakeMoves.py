wh = input().split()
init = input().split()
w = int(wh[0])
h = int(wh[1])
x = int(init[0])
y = int(init[1])

eggs = []

n = int(input())

for i in range(n):
    xy = input().split()
    xy[0] = int(xy[0])
    xy[1] = int(xy[1])
    eggs.append(xy)
    
v = 0
c = 0

while (v < n):
    f = False
    if (eggs[v][0] == x or eggs[v][1] == y or abs(eggs[v][0] - x) == abs(eggs[v][1] - y)):
        c += 1
    else:
        c += 2
        
    x = eggs[v][0]
    y = eggs[v][1]

    v += 1

print(c)
