from sys import stdin, stdout

t = int(stdin.readline())

for ti in range(t):
    n, k = (int(x) for x in stdin.readline().split())
    
    if n <= 4:
        stdout.write("-1\n")
    else:
        a = [15] + [10]*(n-3)
        s = sum(a)
        if k==0:
            a.append(s//2)
            a.append(s-s//2)
            stdout.write(" ".join([str(x) for x in a]))
        else:
            a.append(s//2)
            a.append(s//2)
            stdout.write(" ".join([str(x*k) for x in a]))
        stdout.write("\n")