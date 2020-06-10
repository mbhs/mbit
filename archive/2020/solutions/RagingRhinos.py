num_cars = int(input())

cars = []

for i in range(num_cars):
    input_car = list(map(int, input().split()))

    while not input_car[1] and len(cars) and input_car[0]:
        if cars[len(cars) - 1][1]:
            if input_car[0] < cars[len(cars) - 1][0]:
                cars[len(cars) - 1][0] -= input_car[0]
                input_car[0] = 0
                break
            else:
                input_car[0] -= cars[len(cars) - 1][0]
                cars.pop()
        else:
            break
        
    if input_car[0]:
        cars.append(input_car)

print(len(cars))
for car in cars:
    print(car[0], car[1])
