from itertools import groupby
print(''.join([k * (lambda g: 1 if len(g) == 2 else len(g))(list(g)) for k, g in groupby(input())]))