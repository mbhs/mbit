input_split = list(map(int, input().split()))
num_cones = input_split[2]
money = 0

if input_split[0] * 5 > input_split[1]:
    money = num_cones // 5 * input_split[1]
    num_cones %= 5

money += num_cones * input_split[0]

print(money)
