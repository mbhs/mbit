from sys import stdin, stdout

want = [int(x) for x in stdin.readline().split()]
d = sum(want)
chem = ['a', 'b', 'c']
cups = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]


ans = []
def fill(cup, c):
	ans.append("F " + str(cup) + " " + chem[c])

def empty(cup):
	ans.append("E " + str(cup))

def pour(cup1, cup2):
	ans.append("P " + str(cup1) + " " + str(cup2))

def finish(cup):
	ans.append("! " + str(cup))

def bsearch(c1, amt, c2):
	"""Ends with adding amt1 of c1 and 1-amt of c2 to 3."""
	a = []	#binary representation of amt1
	x = amt
	for i in range(32):
		x *= 2
		if x > 1:
			a.append(1)
			x -= 1
		else:
			a.append(0)

	empty(1)
	empty(2)
	fill(2, c1)
	for i in range(31, -1, -1):
		pour(2, 1)
		empty(1)
		fill(1, c1 if a[i] else c2)
		pour(1, 2)
	pour(2, 1)
	pour(1, 3)

if(want[0] >= want[1] and want[0] >= want[2]):
	bsearch(1, want[1]/d*2, 0)
	bsearch(2, want[2]/d*2, 0)
elif(want[1] >= want[0] and want[1] >= want[2]):
	bsearch(0, want[0]/d*2, 1)
	bsearch(2, want[2]/d*2, 1)
else:
	bsearch(0, want[0]/d*2, 2)
	bsearch(1, want[1]/d*2, 2)

finish(3)
stdout.write(str(len(ans)) + "\n")
stdout.write("\n".join(ans))