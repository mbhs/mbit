#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    long long b, e; cin >> b >> e;

    auto mpow = [](long long b, long long e, long long m) -> long long {
        long long r = 1;
        while (e) {
            if (e & 1) {
                r *= b;
                r %= m;
            }
            b *= b;
            b %= m;
            e >>= 1;
        }
        return r;
    };

    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> par(n);
    vector<int> dep(n);

    function<void(int, int)> dfs_precomp = [&](int u, int p) {
        par[u] = p;
        for (auto& v : g[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            dfs_precomp(v, u);
        }
    };

    dfs_precomp(0, -1);

    for (int i = 1; i < n; ++i) 
        g[i].erase(find(g[i].begin(), g[i].end(), par[i]));

    auto leaf = [&](int x) -> bool {
        if ((int)g[x].size() == 0) return true;
        return false;
    };

    int gcd = 0;

    for (int i = 0; i < n; ++i) 
        if (leaf(i))
            gcd = __gcd(gcd, dep[i] + 1);

    long long residue = mpow(b, e, gcd);

    vector<long double> prob(n);

    function<void(int)> dfs_solve = [&](int u) {
        for (auto& v : g[u]) {
            prob[v] = prob[u] / g[u].size();
            dfs_solve(v);
        }
    };

    prob[0] = 1;
    dfs_solve(0);

    long double sum = 0;

    for (int i = 0; i < n; ++i) 
        sum += prob[i];

    for (int i = 0; i < n; ++i)
        prob[i] /= sum;

    long double ans = 0;

    for (int i = 0; i < n; ++i) 
        if (dep[i] % gcd == residue) 
            ans += prob[i] * gcd * dep[i];
    
    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}