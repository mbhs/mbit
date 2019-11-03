n = int(input())
a = [int(x) for x in input().split()]
for i in a:
    if (i%2==0) ^ (i%3==0):
        print("YES")

    else:
        print("NO")