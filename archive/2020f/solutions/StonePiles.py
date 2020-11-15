from sys import stdin, stdout
print, input = stdout.write, stdin.readline

inp = input().split()
n, m = int(inp[0]), int(inp[1])
ans = []

stacks = [[] for i in range(m)]
for i in range(m):
    stacks[i] = [int(x) for x in input().split()[1:][::-1]]

for i in range(m-1):
    for j in range(len(stacks[i])):
        x = stacks[i].pop()
        stacks[m-1].append(x)
        ans.append(str(i+1)+" "+str(m)+"\n")

for i in range(n):
    x = stacks[m-1].pop()
    if x == m:
        stacks[0].append(x)
        ans.append(str(m)+" "+str(1)+"\n")
    else:
        stacks[x-1].append(x)
        ans.append(str(m)+" "+str(x)+"\n")

cnt = 0
for i in range(len(stacks[0])):
    x = stacks[0].pop()
    if x == m:
        stacks[m-1].append(x)
        ans.append(str(1)+" "+str(m)+"\n")
    else:
        stacks[m-2].append(x)
        ans.append(str(1)+" "+str(m-1)+"\n")
        cnt+=1

for i in range(cnt):
    x = stacks[m-2].pop()
    stacks[0].append(x)
    ans.append(str(m-1)+" "+str(1)+"\n")

print(str(len(ans)) + "\n")
for x in ans:
    print(x)