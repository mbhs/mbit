#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string colors;
    cin >> colors;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = colors[i] - '0';
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(n + 1, -1)));
    vector<int> sub(n);
    function<void(int, int)> dfs = [&](int src, int par) {
        sub[src] = 1;
        for (int nxt: adj[src]) {
            if (nxt == par) {
                continue;
            }
            dfs(nxt, src);
            sub[src] += sub[nxt];
        }
        int cur_size = 1;
        dp[src][0][1] = 0;
        for (int nxt: adj[src]) {
            if (nxt == par) {
                continue;
            }
            for (int j = cur_size; j >= 0; j--) {
                if (dp[src][0][j] != -1) {
                    int bef = dp[src][0][j];
                    for (int k = 0; k <= sub[nxt]; k++) {
                        if (dp[nxt][0][k] != -1) {
                            dp[src][0][j + k] = max(dp[src][0][j + k], bef + dp[nxt][0][k] + k * c[src]);
                        }
                        if (dp[nxt][1][k] != -1) {
                            dp[src][0][j] = max(dp[src][0][j], bef + dp[nxt][1][k] + k);
                        }
                    }
                }
            }
            cur_size += sub[nxt];
        }
        cur_size = 1;
        dp[src][1][c[src]] = 0;
        for (int nxt: adj[src]) {
            if (nxt == par) {
                continue;
            }
            for (int j = cur_size; j >= 0; j--) {
                if (dp[src][1][j] != -1) {
                    int bef = dp[src][1][j];
                    for (int k = 0; k <= sub[nxt]; k++) {
                        if (dp[nxt][1][k] != -1) {
                            dp[src][1][j + k] = max(dp[src][1][j + k], bef + dp[nxt][1][k] + k);
                        }
                        if (dp[nxt][0][k] != -1) {
                            dp[src][1][j] = max(dp[src][1][j], bef + dp[nxt][0][k] + k * c[src]);
                        }
                    }
                }
            }
            cur_size += sub[nxt];
        }
    };
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= n; k++ ){
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
}
