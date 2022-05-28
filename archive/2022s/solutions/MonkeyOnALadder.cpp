#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;

const int N = 500001;
int n, q;

// ----------------------------------------------------------
struct segtree {
    vector<pii> mn;

    segtree() {
        mn.resize(4 * n + 5);
    }

    void build(vector<int> &v, int x = 0, int lx = 1, int rx = n + 1) {
        if (rx - lx == 1) {
            mn[x] = {v[lx], -lx};
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }

    pii get_min(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return mn[x];
        if (lx >= r || rx <= l) return {1e9, 1e9};
        int m = (lx + rx) / 2;
        return min(get_min(l, r, 2 * x + 1, lx, m), get_min(l, r, 2 * x + 2, m, rx));
    }
    pii get_min(int l, int r) { return get_min(l, r, 0, 1, n + 1); }
};
// ----------------------------------------------------------

struct query {
    int i, l, r, a, b;
};

vector<query> qu[N];
ll ps[N];
vector<int> h, c;
ll ans[N];
ll cost[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    segtree segC, segH;

    c.resize(n + 1);
    h.resize(n + 1);
    rep(i, 1, n) cin >> h[i] >> c[i];
    segC.build(c);
    segH.build(h);

    rep(i, 1, q) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        int j = -segH.get_min(l, r + 1).s;
        if (a < h[j]) ans[i] = ll(max(0, min(b, h[j]) - a)) * segC.get_min(l, r + 1).f;
        l = j;
        a = h[j];
        if (b <= a) continue;

        qu[r].pb({i, l, r, a, b});
    }

    vector<int> x, H;
    rep(i, 1, n) {
        while (sz(x) && (h[i] <= h[x.back()] || c[i] <= cost[x.back()])) {
            x.pop_back();
            H.pop_back();
        }
        if (sz(x)) ps[i] = ps[x.back()] + (cost[i] = segC.get_min(x.back() + 1, i + 1).f) * ll(h[i] - H.back());
        x.push_back(i);
        H.push_back(h[i]);

        for (auto qr : qu[i]) {
            int j = *lower_bound(all(x), qr.l);
            int k = (lower_bound(all(H), qr.b) == H.begin() ? -1 : x[lower_bound(all(H), qr.b) - H.begin() - 1]);
            if (k < j) {
                ans[qr.i] += ll(max(0, qr.b - qr.a)) * segC.get_min(qr.l + 1, qr.r + 1).f;
                continue;
            }
            ans[qr.i] += segC.get_min(qr.l + 1, j + 1).f * ll(h[j] - qr.a) + ps[k] - ps[j] + segC.get_min(k + 1, i + 1).f * ll(qr.b - h[k]);
        }
    }

    rep(i, 1, q) cout << ans[i] << nl;
}
