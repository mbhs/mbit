n = int(input())

locations = [int(el) for el in input().split()]
locations.sort()

# Cumulative sum
for i in range(1, n):
    locations[i] += locations[i-1]

# Going through and calculating each possible division, keeping the maximum
max_diff = 0
for i in range(n-1):
    max_diff = max(abs(locations[i] / (i+1) - (locations[-1]-locations[i]) / (n-i-1)), max_diff)

print(max_diff)