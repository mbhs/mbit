# faster io
from sys import stdin, stdout

[a, b, c] = stdin.readline().split()
a = int(a)
b = int(b)
c = int(c)
total = 0
# add Alice's ticket cost
if a < 18:
    total += 10
elif a < 60:
    total += 20
else:
    total += 15
# add Bob's ticket cost
if b < 18:
    total += 10
elif b < 60:
    total += 20
else:
    total += 15
# add Charlie's ticket cost
if c < 18:
    total += 10
elif c < 60:
    total += 20
else:
    total += 15
stdout.write(str(total))
