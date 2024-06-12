// int max = 2 147 483 647 (2^31-1)
// ll max = 9 223 372 036 854 775 807 (2^63-1)
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;

// Fast input and output
void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Printing pairs and vectors
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
    cout << "[";
    forn(i, (int)v.size()) {
        if (i) cout << ", ";
        cout << v[i];
    }
    return cout << "]";
}

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// use uniform_int_distribution<int>(a, b)(rng) if you want [a, b].

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<vi> a(n, vi(3));
    forn(i, n) cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(a.begin(), a.end());
    vector<vl> dp(k + 1, vl(n + 1));
    // dp[i][j] is ans if you only need to eat from [0,i)
    // and you can only buy bananas that rot from [0,r[j])
    forn(i, k + 1) forn(j, n + 1) {
        if (j == 0 or i == 0) {
            if (i == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (ll)MOD * MOD;
            continue;
        }
        if (i > a[j - 1][0])
            dp[i][j] = (ll)MOD * MOD;
        else
            dp[i][j] = min(dp[i][j - 1], a[j - 1][2] + dp[max(0, i - a[j - 1][1])][j - 1]);
    }
    if (dp[k][n] == (ll)MOD * MOD)
        cout << "-1\n";
    else
        cout << dp[k][n] << "\n";
}
// code by DanTheMan
