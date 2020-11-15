#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
const int MAX = 1005;
ll dp[MAX][MAX][2];
ll u[MAX][MAX];
ll d[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    k++;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const ll INF = 1e16;
    for (int i = 0; i < n; i++) {
        u[i][0] = a[i];
        d[i][0] = (a[i] == 0 ? 0 : k - a[i]);
        for (int j = 1; j < n + 1; j++) {
            u[i][j] = u[i][j - 1] + k;
            d[i][j] = d[i][j - 1] + k;
        }
    }
    auto ckmin = [&](ll& x, ll y) -> bool {
        if (x > y) {
            x = min(x, y);
            return true;
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j][0] = d[i][j];
                dp[i][j][1] = u[i][j];
            }
        } else {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j][0] = INF;
                dp[i][j][1] = INF;
            }
            ll mn1 = INF;
            ll mn2 = INF;
            for (int j = 0; j < n + 1; j++) {
                ckmin(mn1, dp[i - 1][j][1]);
                ckmin(mn2, dp[i - 1][j][0]);
            }
            for (int j = 0; j < n + 1; j++) {
                ckmin(dp[i][j][0], mn1 + d[i][j]);
                ckmin(dp[i][j][1], mn2 + u[i][j]);
            }
            for (int j = 0; j < n + 1; j++) {
                ckmin(dp[i][j][0], dp[i - 1][j][0] + max(0LL, d[i][j] - d[i - 1][j]));
                ckmin(dp[i][j][1], dp[i - 1][j][1] + max(0LL, u[i][j] - u[i - 1][j]));
            }
            mn1 = INF;
            mn2 = INF;
            for (int j = 0; j < n + 1; j++) {
                ckmin(dp[i][j][0], mn1 + d[i][j]);
                ckmin(dp[i][j][1], mn2 + u[i][j]);
                ckmin(mn1, dp[i - 1][j][0] - d[i - 1][j]);
                ckmin(mn2, dp[i - 1][j][1] - u[i - 1][j]);
            }
            mn1 = INF;
            mn2 = INF;
            for (int j = n; j >= 0; j--) {
                ckmin(dp[i][j][0], mn1);
                ckmin(dp[i][j][1], mn2);
                ckmin(mn1, dp[i - 1][j][0]);
                ckmin(mn2, dp[i - 1][j][1]);
            }
        }
    }
    ll ans = INF;
    for (int x = 0; x < n + 1; x++) {
        for (int y = 0; y < 2; y++) {
            ckmin(ans, dp[n - 1][x][y]);
        }
    }
    cout << ans << '\n';
    return 0;
}
