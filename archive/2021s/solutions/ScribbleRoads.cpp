#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;

	void init(int n) {
		e = vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) {
			return false;
		}
		if (e[x] > e[y]) {
			std::swap(x, y);
		}
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

const int N = 1e5 + 5;
const int L = 10;

int dp[L][N][2]; 

int solve(int e, int o, int p) {
	if (e >= L) {
		return p ^ ((o % 4) / 2);
	}
	auto& res = dp[e][o][p];
	if (e + o == 1) {
		res = 0;
		return res;
	}
	if (res != -1) {
		return res;
	}
	if (p) {
		int t = solve(e, o, p ^ 1);
		if (t == 0) {
			res = 1;
			return res;
		}
	}
	if (e && o) {
		int t = solve(e - 1, o, p ^ 1);
		if (t == 0) {
			res = 1;
			return res;
		}
	} 
	if (e >= 2) {
		int t = solve(e - 1, o, p ^ 1);
		if (t == 0) {
			res = 1;
			return res;
		}
	} 
	if (o >= 2) {
		int t = solve(e + 1, o - 2, p);
		if (t == 0) {
			res = 1;
			return res;
		}
	}
	res = 0;
	return res;
}

void solve_case(int tc = 0) {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	DSU D; 
	D.init(n);
	for (int i = 0; i < m; ++i) {
		int u, v; 
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		D.unite(u, v);
	}
	vector<int> comps;
	for (int i = 0; i < n; ++i) {
		comps.push_back(D.get(i));
	}	
	sort(comps.begin(), comps.end());
	comps.erase(unique(comps.begin(), comps.end()), comps.end());		
	auto get_pos = [&](int x) -> int {
		return lower_bound(comps.begin(), comps.end(), x) - comps.begin();
	};
	int sz = comps.size();
	vector<int> amt(sz);
	for (int i = 0; i < sz; ++i) {
		amt[i] = D.size(comps[i]);
	}
	int p = 0;
	long long dead = -m;
	for (auto& c : comps) {
		long long sz = D.size(c);
		dead += sz * (sz - 1) / 2;
	}
	p = dead % 2;
	int e = 0;
	int o = 0;
	for (int i = 0; i < sz; ++i) {
		if (amt[i] % 2 == 0) {
			++e; 
		} else {
			++o;
		}
	}
	int ans = solve(e, o, p);
	if (ans == 0) {
		cout << "LOSE" << '\n';
	} else {
		cout << "WIN" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	int tt; 
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		solve_case(tc);
	}
	return 0;
}
