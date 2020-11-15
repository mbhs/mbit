from sys import stdin, stdout

inp = stdin.readline().split()
n, m, k = int(inp[0]), int(inp[1]), int(inp[2])

grid = [[0]*m for i in range(n)]

b = [[999999]*m for i in range(n)]
sb = [[999999]*m for i in range(n)]

for i in range(n):
    line = stdin.readline()
    for j in range(m):
        if line[j] == "#":
            grid[i][j] = 1

rams = []
onone = [0]*k
for i in range(k):
    inp = stdin.readline().split()
    rams.append([int(inp[0])-1, int(inp[1])-1])
    if grid[rams[i][0]][rams[i][1]] == 1:
        grid[rams[i][0]][rams[i][1]] = 0
        onone[i] = 1

for r in range(k):
    visit1 = [rams[r]]
    dist = 0#grid[rams[r][0]][rams[r][1]]
    found = [[-1]*m for i in range(n)]
    found[rams[r][0]][rams[r][1]] = dist

    while len(visit1) > 0:
        visit0 = visit1
        visit1 = []

        while len(visit0) > 0:
            newvisit = []
            for u in visit0:
                if u[0] > 0:
                    if found[u[0]-1][u[1]] == -1:
                        if grid[u[0]-1][u[1]] == 1:
                            found[u[0]-1][u[1]] = dist+1
                            visit1.append([u[0]-1,u[1]])
                        else:
                            found[u[0]-1][u[1]] = dist
                            newvisit.append([u[0]-1,u[1]])
                if u[1] > 0:
                    if found[u[0]][u[1]-1] == -1:
                        if grid[u[0]][u[1]-1] == 1:
                            found[u[0]][u[1]-1] = dist+1
                            visit1.append([u[0],u[1]-1])
                        else:
                            found[u[0]][u[1]-1] = dist
                            newvisit.append([u[0],u[1]-1])
                if u[0] < n-1:
                    if found[u[0]+1][u[1]] == -1:
                        if grid[u[0]+1][u[1]] == 1:
                            found[u[0]+1][u[1]] = dist+1
                            visit1.append([u[0]+1,u[1]])
                        else:
                            found[u[0]+1][u[1]] = dist
                            newvisit.append([u[0]+1,u[1]])
                if u[1] < m-1:
                    if found[u[0]][u[1]+1] == -1:
                        if grid[u[0]][u[1]+1] == 1:
                            found[u[0]][u[1]+1] = dist+1
                            visit1.append([u[0],u[1]+1])
                        else:
                            found[u[0]][u[1]+1] = dist
                            newvisit.append([u[0],u[1]+1])
            visit0 = newvisit

        dist += 1

    for i in range(n):
        for j in range(m):
            if found[i][j]+onone[r] < b[i][j]:
                sb[i][j] = b[i][j]
                b[i][j] = found[i][j]+onone[r]
            elif found[i][j]+onone[r] < sb[i][j]:
                sb[i][j] = found[i][j]+onone[r]

visit1 = [[-1,-1]]
dist = 0
found = [[-1]*m for i in range(n)]

while len(visit1) > 0:
    visit0 = visit1
    visit1 = []

    while len(visit0) > 0:
        newvisit = []
        for u in visit0:
            if u[0] == -1:
                for i in range(n):
                    if grid[i][0] == 1:
                        found[i][0] = 1
                        visit1.append([i,0])
                    else:
                        found[i][0] = 0
                        newvisit.append([i, 0])
                    if grid[i][m-1] == 1:
                        found[i][m-1] = 1
                        visit1.append([i,m-1])
                    else:
                        found[i][m-1] = 0
                        newvisit.append([i, m-1])
                for j in range(1, m-1):
                    if grid[0][j] == 1:
                        found[0][j] = 1
                        visit1.append([0,j])
                    else:
                        found[0][j] = 0
                        newvisit.append([0, j])
                    if grid[n-1][j] == 1:
                        found[n-1][j] = 1
                        visit1.append([n-1,j])
                    else:
                        found[n-1][j] = 0
                        newvisit.append([n-1, j])
                break
            if u[0] > 0:
                if found[u[0]-1][u[1]] == -1:
                    if grid[u[0]-1][u[1]] == 1:
                        found[u[0]-1][u[1]] = dist+1
                        visit1.append([u[0]-1,u[1]])
                    else:
                        found[u[0]-1][u[1]] = dist
                        newvisit.append([u[0]-1,u[1]])
            if u[1] > 0:
                if found[u[0]][u[1]-1] == -1:
                    if grid[u[0]][u[1]-1] == 1:
                        found[u[0]][u[1]-1] = dist+1
                        visit1.append([u[0],u[1]-1])
                    else:
                        found[u[0]][u[1]-1] = dist
                        newvisit.append([u[0],u[1]-1])
            if u[0] < n-1:
                if found[u[0]+1][u[1]] == -1:
                    if grid[u[0]+1][u[1]] == 1:
                        found[u[0]+1][u[1]] = dist+1
                        visit1.append([u[0]+1,u[1]])
                    else:
                        found[u[0]+1][u[1]] = dist
                        newvisit.append([u[0]+1,u[1]])
            if u[1] < m-1:
                if found[u[0]][u[1]+1] == -1:
                    if grid[u[0]][u[1]+1] == 1:
                        found[u[0]][u[1]+1] = dist+1
                        visit1.append([u[0],u[1]+1])
                    else:
                        found[u[0]][u[1]+1] = dist
                        newvisit.append([u[0],u[1]+1])
        visit0 = newvisit

    dist += 1
best = 9999999
fb = 99999999
fsb = 99999999
for i in range(n):
    for j in range(m):
        best = min(best, b[i][j] + sb[i][j] + found[i][j] - (2 if grid[i][j] else 0))

for i in range(len(rams)):
    ram = rams[i]
    if found[ram[0]][ram[1]]+onone[i]< fb:
        fsb = fb
        fb = found[ram[0]][ram[1]]+onone[i]
    elif found[ram[0]][ram[1]]+onone[i] < fsb:
        fsb = found[ram[0]][ram[1]]+onone[i]
best = min(best, fb + fsb)
stdout.write(str(best))
