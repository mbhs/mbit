#include <bits/stdc++.h>

// #include "testlib.h"

using namespace std;

typedef long long ll;

ll n, m, k;
const ll dr[4] = {0, 0, -1, 1};
const ll dc[4] = {1, -1, 0, 0};

bool valid(ll r, ll c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void solve(int argc, char* argv[], int tc = 0) {
	cin >> n >> m >> k;
	
	bool grid[n][m];
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (ll j = 0; j < m; j++) {
			grid[i][j] = (s[j] == '#');
		}
	}
		
	pair<ll, ll> special[k];
	for (ll i = 0; i < k; i++) {
		cin >> special[i].first >> special[i].second;
		--special[i].first;
		--special[i].second;
	}
	
	ll dists[k][n][m];
		
	for (ll i = 0; i < k; i++) {
		deque<pair<pair<ll, ll>, ll>> dq;
		dq.push_front(make_pair(special[i], grid[special[i].first][special[i].second]));
		
		bool vis[n][m];
		memset(vis, 0, sizeof(vis));
		
		while (!dq.empty()) {
			pair<pair<ll, ll>, ll> cur = dq.front();
			dq.pop_front();
			
			pair<ll, ll> loc = cur.first;
			ll r = loc.first, c = loc.second;
			ll dist = cur.second;
			
			if (vis[r][c]) continue;
			vis[r][c] = 1;
			
			dists[i][r][c] = dist;
			
			for (ll d = 0; d < 4; d++) {
				ll nr = r + dr[d], nc = c + dc[d];
				if (valid(nr, nc)) {
					if (grid[nr][nc]) {
						dq.push_back(make_pair(make_pair(nr, nc), dist + 1));
					} else {
						dq.push_front(make_pair(make_pair(nr, nc), dist));
					}
				}
			}
		}
	}
		
	ll edge_dist[n][m];
	
	deque<pair<pair<ll, ll>, ll>> dq;
	for (ll i = -1; i <= n; i++) {
		dq.push_back(make_pair(make_pair(i, -1), 0));
		dq.push_back(make_pair(make_pair(i, m), 0));
	}
	
	for (ll i = -1; i <= m; i++) {
		dq.push_back(make_pair(make_pair(-1, i), 0));
		dq.push_back(make_pair(make_pair(n, i), 0));
	}
		
	bool vis[n][m];
	memset(vis, 0, sizeof(vis));
		
	while (!dq.empty()) {
		pair<pair<ll, ll>, ll> cur = dq.front();
		dq.pop_front();
		
		pair<ll, ll> loc = cur.first;
		ll r = loc.first, c = loc.second;
		ll dist = cur.second;
		
		// cout << r << " " << c << " " << dist << '\n';
		
		if (valid(r, c)) {
			if (vis[r][c]) continue;
			vis[r][c] = 1;
			
			edge_dist[r][c] = dist;
		}
		
		for (ll d = 0; d < 4; d++) {
			ll nr = r + dr[d], nc = c + dc[d];
			if (valid(nr, nc)) {
				if (grid[nr][nc]) {
					dq.push_back(make_pair(make_pair(nr, nc), dist + 1));
				} else {
					dq.push_front(make_pair(make_pair(nr, nc), dist));
				}
			}
		}
	}
		
	ll best = 1e9;
	for (ll i = 0; i < k; i++) {
		for (ll j = i + 1; j < k; j++) {
			best = min(best, edge_dist[special[i].first][special[i].second] + edge_dist[special[j].first][special[j].second]);
		}
	}
		
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll dist_vals[k];
			for (ll x = 0; x < k; x++) {
				dist_vals[x] = dists[x][i][j];
			}
			sort(dist_vals, dist_vals + k);
			
			ll cost = dist_vals[0] + dist_vals[1] + edge_dist[i][j];
			if (grid[i][j]) cost -= 2; // counted 3 times
			
			// cout << i << " " << j << " " << cost << " " << edge_dist[i][j] << '\n';
			
			best = min(best, cost);
		}
	}
		
	cout << best << '\n';
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(argc, argv, t);
} 