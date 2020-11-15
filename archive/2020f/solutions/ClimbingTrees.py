from sys import stdin, stdout
print, input = stdout.write, stdin.readline

inp = input().split()
n, k = int(inp[0]), int(inp[1])

a = [int(x) for x in input().split()]
a.sort()

bef = -k*2
best = 0
curr = 0
for x in a:
    if x <= bef + k:
        curr += x
    else:
        curr = x
    best = max(best, curr)
    bef = x

print(str(best))