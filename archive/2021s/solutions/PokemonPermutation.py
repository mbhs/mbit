# Evan Wang | MBHS 2021

import math

s = input()

if len(s) == 1:
    print("IMPOSSIBLE")
    quit()

cnts = [0] * 26

for c in s:
    cnts[ord(c)-ord('a')] += 1

com_fact = 0
for i in range(26):
    com_fact = math.gcd(com_fact, cnts[i])

if com_fact == 1:
    print("IMPOSSIBLE")
    quit()

for i in range(26):
    cnts[i] //= com_fact
for i in range(com_fact):
    for j in range(26):
        print(str(chr(ord('a') + j)) * cnts[j], end='')
print()
