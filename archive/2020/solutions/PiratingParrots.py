num_commands = int(input())
commands = input()
coords = list(map(int, input().split()))

curr_pos = [0, 0]

for i in range(num_commands):
    if commands[i] == 'U':
        curr_pos[1] += 1
    elif commands[i] == 'D':
        curr_pos[1] -= 1
    elif commands[i] == 'R':
        curr_pos[0] += 1
    else:
        curr_pos[0] -= 1

out = abs(curr_pos[0] - coords[0]) + abs(curr_pos[1] - coords[1])
print(out)
