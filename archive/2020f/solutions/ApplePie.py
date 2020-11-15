numPiesNeeded, basketSize, numApples = map(int, input().split())

# A non-math solution: simulate the process, keep buying baskets as necessary
numPies = 0
while numApples >= 10:  # While we have enough apples to keep making pies, make more
    numPies += 1
    numApples -= 10

if numPies >= numPiesNeeded:    # We already have enough pies, don't need to buy any baskets
    print(0)
else:
    extra = 0   # 'Extra' keeps track of how many extra baskets we buy
    while numPies < numPiesNeeded:  # As long as we don't have sufficient pies, buy another basket
        numApples += basketSize
        extra += 1
        while numApples >= 10:  # While we have enough apples to keep making pies, make more
            numPies += 1
            numApples -= 10
    print(extra)