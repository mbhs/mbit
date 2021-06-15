#include "bits/stdc++.h"
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using ll = long long;

const int C = 3000;
const int B = 17;

vector<vector<int>> dp, at;
vector<int> a;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	a = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	dp = vector<vector<int>>(n / C + 3, vector<int>(1 << B, (1 << 30) - 1));
	at = vector<vector<int>>(1 << B, vector<int>());
	
	for (int i = 0; i < (1 << B); i++) {
		for (int j = 0; j < B; j++) {
			if (!(i & (1 << j))) at[i].push_back(1 << j);
		}
	}
	
	for (int i = 0; i * C < n; i++) {
		for (int j = i * C; j <= min(n - 1, (i + 1) * C - 1); j++) {
			dp[i][a[j]] = a[j];
		}
		
		for (int j = (1 << B) - 1; j >= 0; j--) {
			for (int v = 0; v < at[j].size(); v++) {
				dp[i][j] &= dp[i][j ^ at[j][v]];
			}
		}
	}
		
	for (int i = 0; i < q; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		--l; --r;
		
		int v = (1 << 30) - 1;
		
		int lj = l / C, rj = r / C;
		for (int j = lj; j <= rj; j++) {
			int lv = j * C, rv = min(n - 1, (j + 1) * C - 1);
			
			if (l <= lv && rv <= r) v &= dp[j][x];
			else {
				lv = max(lv, l);
				rv = min(rv, r);
				for (int k = lv; k <= rv; k++) {
					if ((a[k] & x) == x) {
						v &= a[k];
					}
				}
			}
		}
						
		cout << (v == x ? "YES\n" : "NO\n");
	}		
}