def brush_key(brush):
    return brush[0]

input_split = input().split()
num_eggs = int(input_split[0])
curr_pos = int(input_split[1]) - 1

brushes = [[0, i] for i in range(num_eggs)]

input_split = input().split()

for i in range(num_eggs):
    brushes[i][0] = int(input_split[i])

brushes.sort(key=brush_key)

move_dist = 0

for brush in brushes:
    move_dist += abs(brush[1] - curr_pos)
    curr_pos = brush[1]

print(move_dist)
