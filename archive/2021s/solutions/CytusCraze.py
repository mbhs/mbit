from sys import stdin, stdout

(n, k) = (int(x) for x in stdin.readline().split())
bits = len(bin(n))-2
k = min(k, 2**bits-1)
stdout.write(str((pow(2, n-bits, 10**9+7)*(k+1))%(10**9+7)))