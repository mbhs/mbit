from sys import stdin, stdout
input, print = stdin.readline, stdout.write

inp = input().split()
n, x = int(inp[0]), int(inp[1])

v = [max(0, x-int(a)) for a in input().split()]
m = max(v)
s = sum(v)
if m*2 >= s:
    print(str(m))
else:
    if s %2 == 0:
        print(str(s//2))
    else:
        print(str(s//2+1))
