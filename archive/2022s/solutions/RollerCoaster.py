# faster io
from sys import stdin, stdout

tests = int(stdin.readline())
for testcase in range(tests):
    n = int(stdin.readline())
    a = []
    for i in range(n):
        [x, y] = stdin.readline().split()
        a.append((int(x), int(y)))
    # if direction is whether coaster starts going right
    # if direction is true then going left is upside down
    direction = a[0][0] + 1 == a[1][0]
    answer = False
    for i in range(n - 1):
        # if going left is upside down and you're going left
        if direction and (a[i + 1][0] == a[i][0] - 1):
            answer = True
        # if going right is upside down and you're going right
        if not (direction) and (a[i + 1][0] == a[i][0] + 1):
            answer = True
    if answer:
        stdout.write("Yes\n")
    else:
        stdout.write("No\n")
