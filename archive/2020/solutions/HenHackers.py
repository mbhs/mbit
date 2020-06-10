"""
Author: Maxwell Zhang
"""
from functools import cmp_to_key

def ask(s):
    print(s)
    c = input()
    if c == 'C':
        exit()
    return c == 'Y'

def cmp(a, b):
    return -1 if ask(a + b) else 1

ret = []
for i in range(48, 58):
    if ask(chr(i)):
        ret.append(chr(i))
for i in range(65, 91):
    if ask(chr(i)):
        ret.append(chr(i))
for i in range(97, 123):
    if ask(chr(i)):
        ret.append(chr(i))

ret = "".join(sorted(ret, key=cmp_to_key(cmp)))
print(ret)
