# Evan Wang | MBHS 2021

from math import sqrt, isclose

def squDist(p1: list, p2: list):
    return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1])

t = int(input())

for test in range(t):
    n = int(input())
    points1 = []
    for i in range(n):
        coord = input().split()        
        points1.append([int(coord[0]), int(coord[1])])
    points2 = []
    for i in range(n):
        coord = input().split()
        points2.append([int(coord[0]), int(coord[1])])
    
    start1 = start2 = 0
    min1 = min2 = [10 ** 10, 10 ** 10]
    
    for i in range(n):
        if points1[i] < min1:
            min1 = points1[i].copy()
            start1 = i
        if points2[i] < min2:
            min2 = points2[i].copy()
            start2 = i
    
    for i in range(n):
        points1[i][0] -= min1[0]
        points1[i][1] -= min1[1]
        points2[i][0] -= min2[0]
        points2[i][1] -= min2[1]

    scale_factor = sqrt(squDist(points1[start1], points1[(start1+1)%n]) / squDist(points2[start2], points2[(start2+1)%n]))
    
    is_good = True
    for i in range(n):
        ind1 = (i + start1) % n
        ind2 = (i + start2) % n
        points2[ind2][0] *= scale_factor
        points2[ind2][1] *= scale_factor
        if not isclose(points2[ind2][0], points1[ind1][0]) or not isclose(points2[ind2][1], points1[ind1][1]):
            is_good = False
            break

    if is_good:
        print("YES")
    else:
        print("NO")
