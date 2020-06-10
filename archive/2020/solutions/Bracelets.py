num = int(input())

first_in = input().split()
second_in = input().split()

locations = [None] * num
count_common = [0] * num

for i in range(num):
    locations[int(first_in[i]) - 1] = i

for i in range(num):
    count_common[(i - locations[int(second_in[i]) - 1]) % num] += 1

print(max(count_common))
