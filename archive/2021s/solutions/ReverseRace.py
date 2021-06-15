inp = input().strip().split()
for i, w in enumerate(inp):
    nw = [c for c in w[::-1]]
    if nw[-1].isupper():
        nw[-1] = nw[-1].lower()
        nw[0] = nw[0].upper()
    inp[i] = "".join(nw)
inp = inp[::-1]
print(" ".join(inp))
    

