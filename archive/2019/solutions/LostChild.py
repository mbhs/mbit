import math

def main():
    EPS = 0.000000001
    class Point():
        def __init__(self):
            self.x = 0
            self.y = 0
        def __init__(self, x, y):
            self.x = x
            self.y = y
        def dist(self, p):
            return math.sqrt((self.x - p.x) * (self.x - p.x) + (self.y - p.y) * (self.y - p.y))
        def mag(self):
            return math.sqrt(self.x * self.x + self.y * self.y)
        def to(self, p):
            return Point(p.x - self.x, p.y - self.y)
        def add(self, p):
            return Point(p.x + self.x, p.y + self.y)
        def dot(self, p):
            return self.x * p.x + self.y * p.y
        def proj(self, p):
            return self.dot(p)/self.mag()
        def times(self, k):
            return Point(self.x * k, self.y * k)
        def unit(self):
            return self.times(1/self.mag())
        def to_str(self):
            return "(" + str(self.x) + ", " + str(self.y) + ")"

    def minDistance(a, b, c, d):
        v = a.to(b)
        w = c.to(d)
        s = a.to(c)
        t = v.to(w)
        perp = Point(t.y, -t.x)
        if(perp.mag() < EPS):
            return s.mag()
        perpDis = perp.proj(s)
        length = s.dist(s.add(t))
        inter = perp.times(perpDis/perp.mag())
        if(abs(length + s.dist(inter)-s.add(t).dist(inter)) < EPS or abs(length + s.add(t).dist(inter)-s.dist(inter)) < EPS):
            return min(s.mag(),s.add(t).mag())
        else:
            return abs(perpDis)

    inp = input().split()

    n = int(inp[0])
    m = int(inp[1])
    a = int(inp[2])
    b = int(inp[3])

    v1 = []
    v2 = []
    w1 = []
    w2 = []

    for i in range(n):
        inp = input().split()
        x, y = int(inp[0]), int(inp[1])
        v1.append(Point(x,y))
    for i in range(m):
        inp = input().split()
        x, y = int(inp[0]), int(inp[1])
        v2.append(Point(x,y))

    i = 1
    j = 1

    curr = v1[0]
    durr = v2[0]

    w1.append(curr)
    w2.append(durr)

    while(i < n and j < m):
        if(curr.to(v1[i]).mag() < EPS):
            curr = v1[i]
            i += 1
            continue
        if(durr.to(v2[j]).mag() < EPS):
            durr = v2[j]
            j += 1
        if(curr.to(v1[i]).mag()/a < durr.to(v2[j]).mag()/b):
            time = curr.to(v1[i]).mag()/a
            curr = v1[i]
            i += 1
            durr = durr.add(durr.to(v2[j]).unit().times(time*b))
            w1.append(curr)
            w2.append(durr)
        else:
            time = durr.to(v2[j]).mag()/b
            durr = v2[j]
            j += 1
            curr = curr.add(curr.to(v1[i]).unit(). times(time*a))
            w1.append(curr)
            w2.append(durr)

    while(i<n):
        w1.append(v1[i])
        w2.append(v2[m-1])
        i += 1
            
    while(j<m):
        w2.append(v2[j])
        w1.append(v1[n-1])
        j += 1

    minimum = v1[0].to(v2[0]).mag()
    for cnt in range(len(w1) - 1):
        minimum = min(minimum, minDistance(w1[cnt],w1[cnt+1],w2[cnt],w2[cnt+1]))

    print(int(minimum + 0.5))

main()


        
