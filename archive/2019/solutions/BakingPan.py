n = int(input())

minx = 20000001
maxx = -20000001
miny = 20000001
maxy = -20000001
for i in range(n):
    st = [int(x) for x in input().split()]
    minx = min(minx,st[0]-st[2])
    maxx = max(maxx,st[0]+st[2])
    miny = min(miny,st[1]-st[2])
    maxy = max(maxy,st[1]+st[2])

print((maxx-minx)*(maxy-miny))