inp = input().split()
n, m = int(inp[0]), int(inp[1])

zheng = []
yang = []

for i in range(n-1, -1, -1):
    x = range(m) if abs(n-i-1)%2 else range(m-1, -1, -1)
    for j in x:
        zheng.append([i, j])

for j in range(m):
    x = range(n) if abs(j+1)%2 else range(n-1, -1, -1)
    for i in x:
        yang.append([i, j])
cnt = 0

ans = []
for i in range(n*m):
    if zheng[i] == yang[i]:
        ans.append(str(i+1))
        cnt+=1

print(str(cnt)+"\n")
print(" ".join(ans)+"\n")