/*
Monkey on a Ladder
convex
mo's
merge
O((n+q)sqrt(n))
4s TL
*/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define f first
#define s second
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define nl '\n'

const int N = 5e5 + 1;
const int B = 707;
const int K = 20;
int n, q;
int h[N], c[N];
int mn[N][K];
ll ans[N];
vector<int> qu[710];
int l[N], r[N];
pii ij[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> c[i];
        mn[i][0] = h[i];
    }

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            int a = mn[i][k - 1];
            int b = mn[i + (1 << (k - 1))][k - 1];
            mn[i][k] = min(a, b);
        }
    }

    auto get_min = [&](int l, int r) -> int {
        int ans = 1e9;
        for (int i = K - 1; i >= 0; i--) {
            if (l + (1 << i) <= r + 1) {
                ans = min(ans, mn[l][i]);
                l += (1 << i);
            }
        }
        return ans;
    };

    for (int t = 0; t < q; t++) {
        cin >> l[t] >> r[t] >> ij[t].f >> ij[t].s;
        l[t]--;
        r[t]--;
        qu[l[t] / B].push_back(t);
    }

    auto ins = [&](vector<pair<int, int>> &s, vector<ll> &y, int i) {
        int lst = -1;
        while (sz(s) && (s.back().f >= h[i] || s.back().s > c[i])) {
            lst = s.back().f;
            s.pop_back();
            y.pop_back();
        }
        assert(lst != -1);
        if (lst < h[i]) {
            y.push_back((sz(y) ? y.back() : 0) + (sz(s) ? ll(s.back().s) * (lst - s.back().f) : 0));
            s.push_back({lst, c[i]});
        }

        y.push_back((sz(y) ? y.back() : 0) + (sz(s) ? ll(s.back().s) * (h[i] - s.back().f) : 0));
        s.push_back({h[i], 2e9});  // junk
    };

    for (int block = 0; block <= (n - 1) / B; block++) {
        sort(all(qu[block]), [&](int i, int j) { return r[i] < r[j]; });
        int si = (block + 1) * B;
        vector<pair<int, int>> s = {{0, c[si]}, {h[si], 2e9}};
        vector<ll> y = {0, ll(h[si]) * c[si]};
        int j = (block + 1) * B;
        for (int qi : qu[block]) {
            while (j < r[qi]) {
                ins(s, y, ++j);
            }

            vector<pair<int, int>> s2 = {{0, 0}, {ij[qi].f, c[l[qi]]}, {h[l[qi]], 2e9}};
            vector<ll> y2 = {0, 0, ll(h[l[qi]] - ij[qi].f) * c[l[qi]]};

            for (int k = l[qi] + 1; k < min(r[qi] + 1, (block + 1) * B); k++) {
                ins(s2, y2, k);
            }

            if (r[qi] < (block + 1) * B) {
                while (sz(s2) && s2.back().f >= ij[qi].s) s2.pop_back(), y2.pop_back();
                ans[qi] = y2.back() + ll(ij[qi].s - s2.back().f) * s2.back().s;
                continue;
            }

            int x = get_min(si, r[qi]);

            if (sz(s) > 1) assert(s[1].f >= x);

            h[n] = x, c[n] = s.front().s;
            ins(s2, y2, n);

            if (ij[qi].s <= x) {
                while (sz(s2) && s2.back().f >= ij[qi].s) s2.pop_back(), y2.pop_back();
                ans[qi] = y2.back() + ll(ij[qi].s - s2.back().f) * s2.back().s;
                continue;
            }

            ll y0 = y2.back();
            ll y1 = ll(s.front().s) * x;
            int ind = upper_bound(all(s), make_pair(ij[qi].s, -1)) - s.begin() - 1;
            auto lb = s[ind];
            ans[qi] = y[ind] + s[ind].s * ll(ij[qi].s - s[ind].f) - y1 + y0;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
