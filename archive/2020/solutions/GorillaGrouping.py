# import inbuilt standard input output
from sys import stdin, stdout

mod = 1000000007

line = stdin.readline().split()
n = int(line[0])
k = int(line[1])
a = sorted([int(x) for x in stdin.readline().split()])

fib = [1, 1]
for i in range(1000005):
    fib.append((fib[i] + fib[i+1])%mod)

used = [False]*n
d = {}
for x in a:
    d[x] = True

chains = []
for i in range(n):
    if not d[a[i]]:
        continue
    x = a[i]
    p = 0
    while(x in d.keys()):
        d[x] = False
        x += k
        p += 1
    chains.append(p)

ans = 1
for c in chains:
    ans *= fib[c+1]
    ans %= mod

stdout.write(str((ans-1+mod)%mod))
