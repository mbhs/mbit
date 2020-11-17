n = int(input())
a = [int(i) for i in input().split()]

# Main idea: always take leftmost plate
ret = 0
pos = 0 # 'Pos' tracks leftmost plate location
for i in range(n):
    for j in range(a[i]):
        ret += abs(i - pos) # Take leftmost plate, then increment to next plate
        pos += 1
print(ret)