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
    int n, t;
    cin >> n >> t;
    t--;
    vl a(n);
    forn(i, n) cin >> a[i];
    int k;
    cin >> k;                               // time interval for first snapshot
    vector<pair<ll, int>> s(n, mp(0, -1));  // combined list of original and snapshot
    forn(i, n) cin >> s[i].f;
    forn(i, n) s.pb(mp(a[i], i));
    sort(s.begin(), s.end());
    map<ll, queue<int>> occr, occs;
    forn(i, 2 * n) {
        if (s[i].s == -1)
            occs[s[i].f].push(i);
        else
            occr[s[i].f].push(i);
    }
    vector<bool> taken(2 * n);
    vi b(n);
    bool mb = true;
    // cout << s << endl;
    forn(i, 2 * n) {
        if (taken[i]) continue;
        if (s[i].s == -1) {
            if (occr[s[i].f + k].size() == 0)
                mb = false;
            else {
                b[s[occr[s[i].f + k].front()].s] = -1;
                taken[occr[s[i].f + k].front()] = true;
                occr[s[i].f + k].pop();
            }
        } else {
            if (occs[s[i].f + k].size() == 0)
                mb = false;
            else {
                b[s[i].s] = 1;
                taken[occs[s[i].f + k].front()] = true;
                occs[s[i].f + k].pop();
            }
        }
    }
    // cout << b << endl << " " << mb << endl;
    forn(shot, t) {
        ll s;
        cin >> s;
        vl r(n), p(n);
        forn(i, n) cin >> r[i];
        forn(i, n) p[i] = a[i] + b[i] * s;
        sort(p.begin(), p.end());
        if (r != p) mb = false;
    }
    if (!mb)
        cout << "0\n";
    else {
        forn(i, n) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}
// code by DanTheMan
