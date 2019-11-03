#Ice cream

lines = int(input())

grid = []

for i in range(lines):
    grid.append(str(input()))


cb_x = cp_x = cb_y = cp_y = num_b = num_p = 0

for i in range(lines):
    for j in range(lines):
        if grid[i][j] == "p":
            num_p += 1
            cp_x += j
            cp_y += i
        elif grid[i][j] == "b":
            num_b += 1
            cb_x += j
            cb_y += i

cp_x = cp_x/num_p
cb_x = cb_x/num_b
cp_y = cp_y/num_p
cb_y = cb_y/num_b

if(abs(cp_x - cb_x) > abs(cp_y - cb_y)):
    if(cp_x > cb_x):
        print(90)
    else:
        print(270)
else:
    if(cp_y > cb_y):
        print(180)
    else:
        print(0)