/*
Memorable Attractions
*/
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
typedef pair<ll, int> pii;
const int MOD = 1e9 + 7;

const int N = 200001;
int n, k, m, r;
vector<pair<int, ll>> adj[N];
ll dist[N];
ll x[N];
ll p[N];

void dij() {
    rep(i, 0, n) dist[i] = -1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (dist[p.s] != -1) continue;
        dist[p.s] = p.f;
        for (auto e : adj[p.s]) {
            pq.push({p.f + e.s, e.f});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> m;
    rep(i, 0, n - 1) {
        adj[i].pb({i + 1, k});
        adj[i + 1].pb({i, k});
    }
    vector<pair<int, ll>> req;
    rep(i, 1, n) {
        cin >> p[i];
        if (p[i] != -1) {
            adj[0].pb({i, p[i]});
            adj[i].pb({0, p[i]});
            req.pb({i, p[i]});
        }
    }

    rep(i, 1, m) {
        int u, v;
        ll d;
        cin >> u >> v >> d;
        adj[u].pb({v, d});
        adj[v].pb({u, d});
    }

    dij();

    for (auto p : req) {
        if (dist[p.f] != p.s) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES" << nl;
    rep(i, 1, n) cout << dist[i] << " ";
}
