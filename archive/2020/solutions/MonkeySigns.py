sign = input().lower()

chars = dict()
num_m = 0

for letter in sign:
    if letter == 'm':
        num_m += 1
        continue
    chars[letter] = chars.get(letter, 0) + 1

num_m += max(chars.values())

print(num_m)
