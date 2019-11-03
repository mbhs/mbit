import sys
sys.setcheckinterval(2000000000)

mod = 1000000007

def mpow(base, exp):
  res = 1
  while (exp > 0):
    if (exp % 2 == 1):
      res = (res * base) % mod
    base = (base * base) % mod
    exp = int(exp / 2)
  return res

def minv(base):
  return mpow(base, mod - 2)

def mmul(a, b):
  return (a * b) % mod;	

n, q = [int(i) for i in input().split()]

prefix = []
inv_prefix = []
for i in range(n):	
	prefix.append([0, 0])
	inv_prefix.append([0, 0])
arr = [int(i) for i in input().split()]

tree = []
lazy = []
info = []
for i in range(4 * n):	
	tree.append(0)
	lazy.append([0, 0])
	info.append([0, 0])

def init(index, left, right):
	if (left == right):
		info[index][0] = arr[left]
		info[index][1] = 1
		tree[index] = arr[left]
		return tree[index]
	
	mid = int((left + right) / 2)
	
	if left == 0:
		x = 1
		y = 1
	else:
		x = inv_prefix[left - 1][0]
		y = inv_prefix[left - 1][1]
	
	info[index][0] = mmul(prefix[right][0], x)
	info[index][1] = mmul(mmul(prefix[right][1], y), minv(mpow(info[index][0], left)))
	
	a = init(2 * index + 1, left, mid)
	b = init(2 * index + 2, mid + 1, right)
	tree[index] = mmul(a, b)
	return tree[index]
	
def update(left, right, k):
	update_deep(0, 0, n - 1, left, right, k)
	
def update_deep(index, tree_left, tree_right, query_left, query_right, k):
		
	# this node is fully within the query
	if (query_left <= tree_left and tree_right <= query_right):
		lazy[index][0] += k * (tree_left - query_left + 1)
		lazy[index][1] += k
		eval_lazy(index, tree_left, tree_right)
		return tree[index]
	
	# this node is unrelated to the query
	if (tree_left > tree_right or tree_right < query_left or query_right < tree_left):
		eval_lazy(index, tree_left, tree_right)
		return tree[index]
	
	# single index
	if (tree_left == tree_right):
		eval_lazy(index, tree_left, tree_right)
		return tree[index]
	
	eval_lazy(index, tree_left, tree_right)
	
	mid = int((tree_left + tree_right) / 2)
	a = update_deep(2 * index + 1, tree_left, mid, query_left, query_right, k)
	b = update_deep(2 * index + 2, mid + 1, tree_right, query_left, query_right, k)
	tree[index] = mmul(a, b)
	return tree[index]
	
def query(left, right):
	return query_deep(0, 0, n - 1, left, right)
	
def query_deep(index, tree_left, tree_right, query_left, query_right):
	eval_lazy(index, tree_left, tree_right)
	if (query_left <= tree_left and tree_right <= query_right):
		return tree[index]
	
	if (tree_left > tree_right or tree_right < query_left or query_right < tree_left):
		return 1 # base value
	
	mid = int((tree_left + tree_right) / 2)
	a = query_deep(2 * index + 1, tree_left, mid, query_left, query_right)
	b = query_deep(2 * index + 2, mid + 1, tree_right, query_left, query_right)
	return mmul(a, b)

def eval_lazy(index, left, right):
	if (lazy[index][0] == 0 and lazy[index][1] == 0):
		return
	x = mpow(info[index][0], lazy[index][0])
	y = mpow(info[index][1], lazy[index][1])
	tree[index] = mmul(tree[index], mmul(x, y))
	
	if (left != right):
		lazy[index * 2 + 1][0] += lazy[index][0]
		lazy[index * 2 + 1][1] += lazy[index][1]
		lazy[index * 2 + 2][0] += lazy[index][0] + (1 + int((right - left) / 2)) * lazy[index][1]
		lazy[index * 2 + 2][1] += lazy[index][1]
	
	lazy[index] = [0, 0]

prefix[0][0] = arr[0]
for i in range(1, n):
	prefix[i][0] = mmul(prefix[i - 1][0], arr[i])
prefix[0][1] = 1
for i in range(1, n):
	prefix[i][1] = mmul(prefix[i - 1][1], mpow(arr[i], i))
	
for i in range(n):
	inv_prefix[i][0] = minv(prefix[i][0])
	inv_prefix[i][1] = minv(prefix[i][1])

init(0, 0, n - 1)

for query_num in range(q):
	args = [int(i) for i in input().split()]
	args[1] -= 1
	args[2] -= 1
	
	if (args[0] == 1):
		update(args[1], args[2], args[3])
	else:
		print(query(args[1], args[2]))