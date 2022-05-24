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
    int n;
    cin >> n;
    vector<pi> s(n);
    forn(i, n) cin >> s[i].f;
    forn(i, n) s[i].s = i;
    sort(s.begin(), s.end());
    string pans;
    vector<string> ans(n);
    forn(i, n) {
        if (i == 0 or s[i].f != s[i - 1].f) {
            pans = "";
            forn(j, s[i].f) pans.pb('a');
        } else {
            for (int j = s[i].f - 1; j >= 0; j--) {
                if (pans.at(j) != 'z') {
                    pans.at(j)++;
                    break;
                }
                pans.at(j) = 'a';
            }
        }
        ans[s[i].s] = pans;
    }
    forn(i, n) cout << ans[i] << "\n";
}
// code by DanTheMan
