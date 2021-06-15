#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e16;

const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

vl graph[100005];
ll vis[100005];

vpl ret;

void dfs1(ll p, ll v) {
    for (ll u: graph[v]) {
        if (!vis[u]) {
            vis[u] = 1;
            dfs1(v, u);
        }
    }

    if (p != -1)
        ret.pb(mp(p, v));
}

void dfs2(ll v) {
    for (ll u: graph[v]) {
        if (!vis[u]) {
            vis[u] = 1;
            ret.pb(mp(u, v));
            dfs2(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin >> n;

    f0r(i, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    ms(vis, 0);
    vis[0] = 1;

    dfs1(-1, 0);

    ms(vis, 0);
    vis[0] = 1;

    dfs2(0);

    f0r(i, 2 * (n-1)) {
        cout << ret[i].f + 1<< " " << ret[i].s + 1 << "\n";
    }



}