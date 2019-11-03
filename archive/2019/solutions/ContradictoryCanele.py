def main():
    grid = []

    ans = ""

    stin = input().split()
    n = int(stin[0])
    m = int(stin[1])
    k = int(stin[2])
    q = int(stin[3])

    if n % k == 0 and m % q == 0:
        print("NO")
        return
    print("YES")
    for i in range(k):
        for j in range(q):
            grid.append(k * q - (i * q + j) - 1)

    grid[k * q - 1] = -(k * q) * (k * q - 1) / 2
    for i in range(n):
        for j in range(m):
            print(int(-grid[(i % k) * q + (j % q)]), end=' ')
        print()
    
    return

main()
