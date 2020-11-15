#include <bits/stdc++.h>

// #include "testlib.h"

using namespace std;

typedef long long ll;

const ll mx = 405;
ll a[405][405];
ll sum[405][405][2];
ll diag[405][405][2];
ll dp[2][405][405];

void solve(int argc, char* argv[], int tc = 0) {
	ll n;
	cin >> n;
	
	memset(a, 0, sizeof(a));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= i; j++) {
			cin >> a[i][j];
			--a[i][j];
		}
	}
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < 2; k++) {
				sum[i][j][k] = (a[i][j] == k + 1);
				if (i > 0) sum[i][j][k] += sum[i - 1][j][k];
				if (j > 0) sum[i][j][k] += sum[i][j - 1][k];
				if (i > 0 && j > 0) sum[i][j][k] -= sum[i - 1][j - 1][k];
			}
		}
	}
	
	auto get_range = [&](ll r1, ll r2, ll c1, ll c2, ll k) {
		--k;
		ll x = sum[r2][c2][k];
		if (r1 > 0) x -= sum[r1 - 1][c2][k];
		if (c1 > 0) x -= sum[r2][c1 - 1][k];
		if (r1 > 0 && c1 > 0) x += sum[r1 - 1][c1 - 1][k];
		return x;
	};
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < 2; k++) {
				diag[i][j][k] = (a[i][j] == k + 1);
				if (i > 0 && j > 0) diag[i][j][k] += diag[i - 1][j - 1][k];
			}
		}
	}
	
	auto get_diag = [&](ll r1, ll r2, ll c1, ll c2, ll k) {
		--k;
		ll x = diag[r2][c2][k];
		if (r1 > 0 && c1 > 0) x -= diag[r1 - 1][c1 - 1][k];
		return x;
	};
	
	memset(dp, 0, sizeof(dp));
	
	ll ans = 0;
	
	for (ll a = 0; a <= n; a++) {
		for (ll b = 0; b + a <= n; b++) {
			for (ll c = 0; c + b + a <= n; c++) {
				ll cur_size = n - (a + b + c) + 1;
		
				ll bot_row = a + c, bot_col = a;
				ll top_row = (n - 1) - b, top_col = (n - 1) - b - c;
				
				if (c > 0) {
					ll diag_1 = get_diag(bot_row - 1, top_row, bot_col, top_col + 1, 1);
					ll diag_2 = get_diag(bot_row - 1, top_row, bot_col, top_col + 1, 2);
					ll diag_ans = max({cur_size - diag_1 - diag_2, diag_1, diag_2});
					dp[a & 1][b][c] = max(dp[a & 1][b][c], dp[a & 1][b][c - 1] + diag_ans);
				}
				
				if (a > 0) {
					ll col_1 = get_range(bot_row - 1, top_row, bot_col - 1, bot_col - 1, 1);
					ll col_2 = get_range(bot_row - 1, top_row, bot_col - 1, bot_col - 1, 2);
					ll col_ans = max({cur_size - col_1 - col_2, col_1, col_2});
					dp[a & 1][b][c] = max(dp[a & 1][b][c], dp[!(a & 1)][b][c] + col_ans);
				}
				
				if (b > 0) {
					ll row_1 = get_range(top_row + 1, top_row + 1, bot_col, top_col + 1, 1);
					ll row_2 = get_range(top_row + 1, top_row + 1, bot_col, top_col + 1, 2);
					ll row_ans = max({cur_size - row_1 - row_2, row_1, row_2});
					dp[a & 1][b][c] = max(dp[a & 1][b][c], dp[a & 1][b - 1][c] + row_ans);
				}
				
				if (a + b + c == n) {
					ans = max(ans, dp[a & 1][b][c]);
				}
			}
		}
	}
	
	cout << ans - 1 << '\n';
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(argc, argv, t);
} 