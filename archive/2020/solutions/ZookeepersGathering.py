class node:

    def __init__(self, n, *args):
        self.n = n
        if len(args) == 0:
            
            self.l = [n,0,0,0,0]
            self.r = [n,0,0,0,0]
            self.mid = [n,0,0,0,0]
        else:
            self.l = args[0]
            self.r = args[1]
            self.mid = args[2]

    def __str__(self):
        return str(self.l) + " | " + str(self.mid) + " | " + str(self.r) + "\n"

    def shift(self, change):
        if change == 0:
            return

        if change > 0:
            if change == 1:
                self.l = [0, self.l[0], self.l[1], self.l[2], self.l[3]]
                self.r = [0, self.r[0], self.r[1], self.r[2], self.r[3]]
                self.mid = [0, self.mid[0], self.mid[1], self.mid[2], self.mid[3]]
            elif change == 2:
                self.l = [0, 0, self.l[0], self.l[1], self.l[2]]
                self.r = [0, 0, self.r[0], self.r[1], self.r[2]]
                self.mid = [0, 0, self.mid[0], self.mid[1], self.mid[2]]
            elif change == 3:
                self.l = [0, 0, 0, self.l[0], self.l[1]]
                self.r = [0, 0, 0, self.r[0], self.r[1]]
                self.mid = [0, 0, 0, self.mid[0], self.mid[1]]
            elif change == 4:
                self.l = [0, 0, 0, 0, self.l[0]]
                self.r = [0, 0, 0, 0, self.r[0]]
                self.mid = [0, 0, 0, 0, self.mid[0]]
        else:
            if change == -1:
                self.l = [self.l[1], self.l[2], self.l[3], self.l[4], 0]
                self.r = [self.r[1], self.r[2], self.r[3], self.r[4], 0]
                self.mid = [self.mid[1], self.mid[2], self.mid[3], self.mid[4], 0]
            elif change == -2:
                self.l = [self.l[2], self.l[3], self.l[4], 0, 0]
                self.r = [self.r[2], self.r[3], self.r[4], 0, 0]
                self.mid = [self.mid[2], self.mid[3], self.mid[4], 0, 0]
            elif change == -3:
                self.l = [self.l[3], self.l[4], 0, 0, 0]
                self.r = [self.r[3], self.r[4], 0, 0, 0]
                self.mid = [self.mid[3], self.mid[4], 0, 0, 0]
            elif change == -4:
                self.l = [self.l[4], 0, 0, 0, 0]
                self.r = [self.r[4], 0, 0, 0, 0]
                self.mid = [self.mid[4], 0, 0, 0, 0]

    def merge(a, b):
        n = a.n + b.n
        l = []
        r = []
        mid = []
        for i in range(5):
            if a.l[i] == a.n:
                l.append(a.n + b.l[i])
            else:
                l.append(a.l[i])
            if b.r[i] == b.n:
                r.append(b.n + a.r[i])
            else:
                r.append(b.r[i])
            mid.append(max(a.mid[i], b.mid[i], a.r[i] + b.l[i]))

        return node(n, l, r, mid)
            

class segtree:
    def __init__(self, n):
        self.n = n
        self.tree = [0 for i in range(4*n)]
        self.lazy = [0 for i in range(4*n)]

        self.init(0, 0, n-1)

    def init(self, i, l, r):
        self.tree[i] = node(r-l+1)
        mid = (l + r)//2
        if r>l:
            self.init(2*i+1, l, mid)
            self.init(2*i+2, mid+1, r)
        

    def update(self, l, r, change):
        self.update_helper(0, 0, self.n-1, l, r, change)

    def update_helper(self, i, tl, tr, ql, qr, change):
        self.eval_lazy(i, tl, tr)
        if ql <= tl and tr <= qr:
            self.lazy[i] += change
            self.eval_lazy(i, tl, tr)
            return self.tree[i]
        if tl >= tr or tr < ql or qr < tl:
            return self.tree[i]

        mid = (tl + tr)//2
        a = self.update_helper(2*i+1, tl, mid, ql, qr, change)
        b = self.update_helper(2*i+2, mid+1, tr, ql, qr, change)

        self.tree[i] = node.merge(a, b)
        return self.tree[i]

    def query(self):
        return self.tree[0].mid[0]
    

    def eval_lazy(self, i, l, r):
        self.tree[i].shift(self.lazy[i])
        

        if l != r:
            self.lazy[i*2 + 1] += self.lazy[i]
            self.lazy[i*2 + 2] += self.lazy[i]

        self.lazy[i] = 0

from sys import stdin, stdout

def main():
    n = int(stdin.readline())
    s = segtree(n+1)
    for i in range(4):
        mi = int(stdin.readline())
        for j in range(mi):
            line = stdin.readline().split()
            s.update(int(line[0]), int(line[1]), 1)
            
    q = int(stdin.readline())
    for i in range(q):
        person, t, l, r = stdin.readline().split()
        s.update(int(l), int(r), 1-2*int(t))
        stdout.write(str(s.query()) + "\n")
        #for x in s.tree:
        #    print(x)
        #print("--")
        #print(s.tree[0].l, s.tree[0].r, s.tree[0].mid)
    
    
    
main()
