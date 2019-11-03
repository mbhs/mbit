#Frosting Patterns

info = input()

info = info.split()

chars = int(info[0])
n = int(info[1])

#print(chars, n)

s = str(input())

def check_patterns(s, p, l):
    for i in range(l):
        if(s[i] != p[i % len(p)]):
            return False

    return True

t = ""
len_t = 0

for i in range(chars):
    t += s[i]
    len_t += 1
    if check_patterns(s, t, chars):
        break

ans = ""

for i in range(n):
    ans += t[(chars + i) % len_t]

print(ans)
    
