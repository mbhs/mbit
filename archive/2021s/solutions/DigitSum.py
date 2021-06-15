# Evan Wang | MBHS 2021

n, m = input().split()
n = int(n)
m = int(m)

if n == 0:
    if m != 1:
        print(-1)
    else:
        print(0)
elif m * 9 < n:
    print(-1)
else:
    remain = n
    for i in range(m):
        if remain >= 9:
            print(9, end='')
            remain -= 9
        else:
            print(remain, end='')
            remain = 0
    print()