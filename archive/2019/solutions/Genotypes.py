n = int(input())
s = input()
t = input()
count = 1
for i in range(n):
    if s[i] != t[i]:
        count *=2
print(count)