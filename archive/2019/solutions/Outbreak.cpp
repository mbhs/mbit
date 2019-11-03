#include <bits/stdc++.h>
 
using namespace std;
 
const long long mod = 1000000007;

inline long long mpow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}

inline long long minv(long long base) {
  return mpow(base, mod - 2);
}

inline long long mmul(long long x, long long y) {
  return (x * y) % mod;
}

long long pre[15005][2];
long long o[15005];

struct segtree {
  long long n, depth;
  vector<long long> tree;
  vector<pair<long long, long long> > stats, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<long long>(4 * s, 0);
    lazy = vector<pair<long long, long long> >(4 * s, make_pair(0, 0));
    stats = vector<pair<long long, long long> >(4 * s, make_pair(0, 0));
    init(0, 0, n - 1, arr);
  }

  long long init(long long i, long long l, long long r, long long* arr) {
    if (l == r) {
      stats[i].first = arr[l];
      stats[i].second = 1;
      return tree[i] = arr[l];
    }

    long long mid = (l + r) / 2;
    long long a = init(2 * i + 1, l, mid, arr),
              b = init(2 * i + 2, mid + 1, r, arr);
    
    long long x = (l ? pre[l - 1][0] : 1);
    long long y = (l ? pre[l - 1][1] : 1);
    stats[i].first = mmul(pre[r][0], minv(x)); /* range mul */
    stats[i].second = mmul(mmul(pre[r][1], minv(y)), minv(mpow(stats[i].first, l))); /* range special mul / (range mul ^ (l - 1)) */
    return tree[i] = mmul(a % mod, b % mod);
  }

  void update(long long l, long long r, long long k) {
    update(0, 0, n - 1, l, r, k);
  }

  long long update(long long i, long long tl, long long tr, long long ql, long long qr, long long k) {
    if (ql <= tl && tr <= qr) {
      lazy[i].first += k * (tl - ql + 1);
      lazy[i].second += k;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl || tl == tr) {
		eval_lazy(i, tl, tr);
		return tree[i];
	}
	
	if (tl != tr) {
      lazy[i * 2 + 1].first += lazy[i].first;
      lazy[i * 2 + 1].second += lazy[i].second;
      lazy[i * 2 + 2].first += lazy[i].first + ((tr - tl) / 2 + 1) * lazy[i].second;
      lazy[i * 2 + 2].second += lazy[i].second;
    }
	lazy[i] = make_pair(0LL, 0LL);

    long long mid = (tl + tr) / 2;
    long long a = update(2 * i + 1, tl, mid, ql, qr, k),
       b = update(2 * i + 2, mid + 1, tr, ql, qr, k);
    return tree[i] = mmul(a % mod, b % mod);
  }

  long long query(long long l, long long r) {
    return query(0, 0, n-1, l, r);
  }

  long long query(long long i, long long tl, long long tr, long long ql, long long qr) {    
  eval_lazy(i, tl, tr);
    if (ql <= tl && tr <= qr) {
		
		return tree[i];
	}
    if (tl > tr || tr < ql || qr < tl) return 1;

    long long mid = (tl + tr) / 2;
    long long a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return mmul(a % mod, b % mod);
  }

  void eval_lazy(long long i, long long l, long long r) {
	if (lazy[i] == make_pair(0LL, 0LL)) return;
    long long x = mpow(stats[i].first, lazy[i].first);
    long long y = mpow(stats[i].second, lazy[i].second);
    tree[i] = mmul(tree[i], mmul(x, y));

    if (l != r) {
      lazy[i * 2 + 1].first += lazy[i].first;
      lazy[i * 2 + 1].second += lazy[i].second;
      lazy[i * 2 + 2].first += lazy[i].first + ((r - l) / 2 + 1) * lazy[i].second;
      lazy[i * 2 + 2].second += lazy[i].second;
    }

    lazy[i] = make_pair(0LL, 0LL);
  }
};

segtree st;

int main() {
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
    cin >> o[i];

  pre[0][0] = o[0];
  for (int i = 1; i < n; i++)
    pre[i][0] = mmul(pre[i - 1][0], o[i]);
  pre[0][1] = 1;
  for (int i = 1; i < n; i++)
    pre[i][1] = mmul(pre[i - 1][1], mpow(o[i], i));

  st.init(n, o);
  for (int i = 0; i < q; i++) {
    int type, l, r; 
    cin >> type >> l >> r;
    --l; --r;
    
    if (type == 1) {
      long long x; cin >> x;
      st.update(l, r, x);
    } else {
      cout << st.query(l, r) << '\n';
    }
  }
}
