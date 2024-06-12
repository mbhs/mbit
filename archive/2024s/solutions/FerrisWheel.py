# faster io
from sys import stdin, stdout

[n, k] = stdin.readline().split()
n = int(n)
k = int(k)
t = stdin.readline().split()
# high is the net rotation closest to 180 degrees
high = 0
# ans is the index of t that corresponds to high
ans = 0
for i in range(n):
    x = (int(t[i]) % k) / k
    # if rotation went past halfway, it becomes reflected
    if x > 0.5:
        x = 1 - x
    # if this is the new highest
    if x > high:
        high = x
        ans = i
stdout.write(str(ans + 1))
