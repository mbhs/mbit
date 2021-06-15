n = int(input())
r = [0] + [int(i) for i in input().split(" ")]
print(sum([1 + abs(c[0] - c[1]) for c in [(r[i], r[(i+1) % (n+1)]) for i in range(n+1)]])-1)