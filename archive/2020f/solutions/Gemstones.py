from sys import stdin, stdout

if __name__=="__main__":
    n = int(stdin.readline())
    grid = [0]*n*n

    for i in range(n):
        x = stdin.readline().split()
        for j in range(i+1):
            grid[i*n+j] = int(x[j])

    oneH = [0]*n*n
    twoH = [0]*n*n
    thrH = [0]*n*n
    oneV = [0]*n*n
    twoV = [0]*n*n
    thrV = [0]*n*n
    oneD = [0]*n*n
    twoD = [0]*n*n
    thrD = [0]*n*n

    for i in range(n):
        for j in range(i+1):
            if j==0:
                if grid[i*n+j] == 1:
                    oneH[i*n+j] = 1
                elif grid[i*n+j] == 2:
                    twoH[i*n+j] = 1
                elif grid[i*n+j] == 3:
                    thrH[i*n+j] = 1
            else:
                if grid[i*n+j] == 1:
                    oneH[i*n+j] = oneH[i*n+j-1] + 1
                    twoH[i*n+j] = twoH[i*n+j-1]
                    thrH[i*n+j] = thrH[i*n+j-1]
                elif grid[i*n+j] == 2:
                    oneH[i*n+j] = oneH[i*n+j-1]
                    twoH[i*n+j] = twoH[i*n+j-1] + 1
                    thrH[i*n+j] = thrH[i*n+j-1]
                elif grid[i*n+j] == 3:
                    oneH[i*n+j] = oneH[i*n+j-1]
                    twoH[i*n+j] = twoH[i*n+j-1]
                    thrH[i*n+j] = thrH[i*n+j-1] + 1

        for j in range(i, n):
            if j==i:
                if grid[j*n+i] == 1:
                    oneV[j*n+i] = 1
                elif grid[j*n+i] == 2:
                    twoV[j*n+i] = 1
                elif grid[j*n+i] == 3:
                    thrV[j*n+i] = 1
            else:
                if grid[j*n+i] == 1:
                    oneV[j*n+i] = oneV[(j-1)*n+i] + 1
                    twoV[j*n+i] = twoV[(j-1)*n+i]
                    thrV[j*n+i] = thrV[(j-1)*n+i]
                elif grid[j*n+i] == 2:
                    oneV[j*n+i] = oneV[(j-1)*n+i]
                    twoV[j*n+i] = twoV[(j-1)*n+i] + 1
                    thrV[j*n+i] = thrV[(j-1)*n+i]
                elif grid[j*n+i] == 3:
                    oneV[j*n+i] = oneV[(j-1)*n+i]
                    twoV[j*n+i] = twoV[(j-1)*n+i]
                    thrV[j*n+i] = thrV[(j-1)*n+i] + 1

        for j in range(n-i):
            if j==0:
                if grid[i*n+j] == 1:
                    oneD[i*n+j] = 1
                elif grid[i*n+j] == 2:
                    twoD[i*n+j] = 1
                elif grid[i*n+j] == 3:
                    thrD[i*n+j] = 1
            else:
                if grid[(i+j)*n+j] == 1:
                    oneD[(i+j)*n+j] = oneD[(i+j-1)*n+j-1] + 1
                    twoD[(i+j)*n+j] = twoD[(i+j-1)*n+j-1]
                    thrD[(i+j)*n+j] = thrD[(i+j-1)*n+j-1]
                elif grid[(i+j)*n+j] == 2:
                    oneD[(i+j)*n+j] = oneD[(i+j-1)*n+j-1]
                    twoD[(i+j)*n+j] = twoD[(i+j-1)*n+j-1] + 1
                    thrD[(i+j)*n+j] = thrD[(i+j-1)*n+j-1]
                elif grid[(i+j)*n+j] == 3:
                    oneD[(i+j)*n+j] = oneD[(i+j-1)*n+j-1]
                    twoD[(i+j)*n+j] = twoD[(i+j-1)*n+j-1]
                    thrD[(i+j)*n+j] = thrD[(i+j-1)*n+j-1] + 1

    dp = [0]*n*n
    for sz in range(1, n):
        new = [0]*n*n
        for i in range(n-sz):
            for j in range(i+1):
                new[i*n+j] = max(new[i*n+j], dp[i*n+j] + max(oneH[(i+sz)*n+j+sz] - (oneH[(i+sz)*n+j-1] if j>0 else 0),
                                                          twoH[(i+sz)*n+j+sz] - (twoH[(i+sz)*n+j-1] if j>0 else 0),
                                                          thrH[(i+sz)*n+j+sz] - (thrH[(i+sz)*n+j-1] if j>0 else 0)))
                new[i*n+j] = max(new[i*n+j], dp[(i+1)*n+j+1] + max(oneV[(i+sz)*n+j] - (oneV[(i-1)*n+j] if i>0 else 0),
                                                              twoV[(i+sz)*n+j] - (twoV[(i-1)*n+j] if i>0 else 0),
                                                              thrV[(i+sz)*n+j] - (thrV[(i-1)*n+j] if i>0 else 0)))
                new[i*n+j] = max(new[i*n+j], dp[(i+1)*n+j] + max(oneD[(i+sz)*n+j+sz] - (oneD[(i-1)*n+j-1] if j>0 else 0),
                                                            twoD[(i+sz)*n+j+sz] - (twoD[(i-1)*n+j-1] if j>0 else 0),
                                                            thrD[(i+sz)*n+j+sz] - (thrD[(i-1)*n+j-1] if j>0 else 0)))
        dp = new
        #print(sz, dp)

    stdout.write(str(dp[0]))

