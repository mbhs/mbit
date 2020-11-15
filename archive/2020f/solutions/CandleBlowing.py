from sys import stdin, stdout
input, print = stdin.readline, stdout.write

inp = input().split()
n, m, k, b = int(inp[0]), int(inp[1]), int(inp[2]), int(inp[3])

grid = [[0]*m for i in range(n)]
blows = input().strip()
nor, sou, wes, eas = [], [], [], []

for i in range(k):
    inp = input().split()
    x, y = int(inp[0])-1, int(inp[1])-1
    grid[x][y] += 1
    nor.append([x, y])
    sou.append([x, y])
    wes.append([x, y])
    eas.append([x, y])

cnt = k

for blow in blows:
    if blow=="N":
        new = []
        for coord in nor:
            if coord[0] > 0 and grid[coord[0]-1][coord[1]]==0:
                new.append([coord[0]-1, coord[1]])
                grid[coord[0]-1][coord[1]]=1
        nor = new
        sou.extend(new)
        wes.extend(new)
        eas.extend(new)
        cnt += len(new)
    if blow=="S":
        new = []
        for coord in sou:
            if coord[0] < n-1 and grid[coord[0]+1][coord[1]]==0:
                new.append([coord[0]+1, coord[1]])
                grid[coord[0]+1][coord[1]]=1
        sou = new
        nor.extend(new)
        wes.extend(new)
        eas.extend(new)
        cnt += len(new)
    if blow=="W":
        new = []
        for coord in wes:
            if coord[1] > 0 and grid[coord[0]][coord[1]-1]==0:
                new.append([coord[0], coord[1]-1])
                grid[coord[0]][coord[1]-1]=1
        wes = new
        sou.extend(new)
        nor.extend(new)
        eas.extend(new)
        cnt += len(new)
    if blow=="E":
        new = []
        for coord in eas:
            if coord[1] < m-1 and grid[coord[0]][coord[1]+1]==0:
                new.append([coord[0], coord[1]+1])
                grid[coord[0]][coord[1]+1]=1
        eas = new
        sou.extend(new)
        wes.extend(new)
        nor.extend(new)
        cnt += len(new)

    print(str(cnt)+"\n")
