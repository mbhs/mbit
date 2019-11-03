s = input()
v = ['a','e','i','o','u']
c = 0
for word in s.split(' '):
    c += sum([word.count(x) for x in v])
    if word[-1] == 'y':
        c+=1
print(c)