"""
Author: Maxwell Zhang
"""
def solve(n):
    ret = n
    while n > 0:
        if n % 10 == 7:
            return 0
        ret += n % 10
        n //= 10
    return ret

a, b = [int(i) for i in input().split()]

ret = 0
for i in range(a, b + 1):
    ret += solve(i)

print(ret)
