def gcd(a, b):
    if a>b:
        return gcd(b,a)
    if a==0:
        return b
    return gcd(b%a, a)

def extended_gcd(a, b):
    if(a==0):
        return b, 0, 1
    
    g, y, x = extended_gcd(b%a, a)
    return g, x - b//a * y, y


def minv(a, m):
    '''Computes modular inverse of a mod m, works for m not prime.
      a must be relatively prime with m.'''
    g, x, y = extended_gcd(a, m)
    assert (g == 1)
    return x % m


n = int(input())

line = input().split()
h, w = int(line[0]), int(line[1])


    
data = [[int(x) for x in input().split()] for y in range(n)]

t = int(input())

def solve(i, j):
    rel = [data[i][x] - data[j][x] for x in range(4)]
    x,y,xv,yv = rel[0],rel[1],rel[2],rel[3]
    x %= w
    y %= h
    nt = t
    #print(x, y, xv, yv)
    if xv == 0:
        if yv == 0:
            if x==0 and y==0:
                print("Asteroids same value")
                return -99999999
            else:
                return 0
        else:
            if x==0:
                if yv > 0:
                    first = (h-y)
                else:
                    first = y
                
                pd = h
                nt = t*yv
                
            else:
                return 0
    else:
        if yv == 0:
            if y==0:
                if xv > 0:
                    first = (w-x)
                else:
                    first = x
                pd = w
                nt = t*xv
            else:
                return 0
        else:
            
            nw = w*abs(yv)
            x *= abs(yv)
            nh = h*abs(xv)
            y *= abs(xv)
            if xv < 0:
                x = (-x)%nw
            if yv < 0:
                y = (-y)%nh
            #print(x, y, nh, nw, xv, yv)
            #get to top/bottom
            curr = (nh-y)%nh
            #print(curr)
            x = (x+curr)%nw

            g = gcd(nh,nw)
            if x%g == 0:
                x//=g
                ah = nh//g
                aw = nw//g
            else:
                return 0
            inv = minv(ah, aw)
            first = curr + nh*((inv*(aw-x))%aw)
            pd = aw*nh

            nt = t*abs(xv*yv)

    nt = abs(nt)
    #print(first, pd, nt)
    if first>nt:
        return 0
    if first == nt:
        return 1

    nt = abs(nt)

    #print(pd, first, nt)
    return 1+(nt-first)//pd

ans = 0
for i in range(n):
    for j in range(i+1, n):
        x = solve(i, j)
        #if x != 0:
            #print(x, i, j)
        ans += solve(i, j)
print(ans)
