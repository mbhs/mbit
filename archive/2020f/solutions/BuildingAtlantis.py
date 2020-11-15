from heapq import heappush, heappop
from sys import stdin, stdout

if __name__=="__main__":
    i = stdin.readline().split()
    n = int(i[0])
    m = int(i[1])

    class Robot:
        def __init__(self, l, r, a):
            self.l = l
            self.r = r
            self.a = a

    v = []
    for i in range(m):
        inp = stdin.readline().split()
        v.append(Robot(int(inp[0]), int(inp[1]), int(inp[2])))

    v.sort(key=lambda x: x.l)

    lo = 0
    hi = 10**15
    

    while abs(1 - lo/hi) > .0000001:
        mid = (hi+lo)/2
        ind = 0
        h = []  #Tuples of (r, a)
        works = True
        for p in range(1, n+1):
            while ind < m and v[ind].l == p:
                heappush(h, (v[ind].r, v[ind].a))
                ind+=1

            x = mid
            while x>0 and len(h)>0:
                r = heappop(h)
                if r[0] < p:
                    works = False
                    break
                if r[1] > x:
                    heappush(h, (r[0], r[1]-x))
                    x = 0
                else:
                    x -= r[1]
                
            if not(works):
                break

        if len(h) > 0:
                works = False
                
        if works:
            #print("works", mid)
            hi = mid
        else:
            lo = mid
            #print("nw", mid)

    H = mid

    lo = 0
    hi = 10**15
    while abs(1 - lo/hi) > .0000001:
        mid = (hi+lo)/2
        ind = 0
        h = []  #Tuples of (r, a)
        works = True
        for p in range(1, n+1):
            while ind < m and v[ind].l == p:
                heappush(h, (v[ind].r, v[ind].a))
                ind+=1

            x = mid
            while x>0 and len(h)>0:
                r = heappop(h)
                if r[0] < p:
                    continue
                if r[1] >= x:
                    heappush(h, (r[0], r[1]-x))
                    x = 0
                else:
                    x -= r[1]

            if x>0:
                works = False
                break

        if works:
            lo = mid
        else:
            hi = mid

    L = mid
    stdout.write(str(L/H))
