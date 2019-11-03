n, k = [int(i) for i in input().split()]
p = [int(i)-1 for i in input().split()]

cycleLength = 1
node = 0
a = [0]
while p[node] != 0:
    cycleLength += 1
    a.append(p[node])
    node = p[node]

print(a[k % cycleLength]+1)
