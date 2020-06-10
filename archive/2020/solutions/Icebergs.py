curr_ship = [0, 0, 0]

def get_dist(val):
    return (all_ships[val][0] - curr_ship[0]) * (all_ships[val][0] - curr_ship[0]) + (all_ships[val][1] - curr_ship[1]) * (all_ships[val][1] - curr_ship[1])


num_ships = int(input())

all_ships = [[0, 0, 0] for i in range(num_ships)]
curr_destroyed = [1] * num_ships
closest = [[j for j in range(num_ships)] for i in range(num_ships)]

for i in range(num_ships):
    in_line = input().split()
    all_ships[i][0] = int(in_line[0])
    all_ships[i][1] = int(in_line[1])
    
for i in range(num_ships):
    curr_ship = all_ships[i]
    closest[i].sort(key=get_dist)

num_destroyed = 0
output = 0
while num_destroyed < num_ships - 1:
    for i in range(num_ships):
        if all_ships[i][2]:
            continue
        num_destroyed += 1

        curr_ship = all_ships[i]
        output = i
        for j in range(curr_destroyed[i], num_ships):
            if not all_ships[closest[i][j]][2]:
                all_ships[closest[i][j]][2] = 1
                curr_destroyed[i] += 1
                break

print(output+1)
