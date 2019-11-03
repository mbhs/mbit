x, y = [int(i) for i in input().split()]

layer = max(abs(x), abs(y))
ret = 4 * layer * (layer - 1)
if x == layer:
    ret += layer + y
elif y == layer:
    ret += 3 * layer - x
elif x == -layer:
    ret += 5 * layer - y
else:
    ret += 7 * layer + x

print(ret)