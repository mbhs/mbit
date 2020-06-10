#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 105;

const int MOD = 1e9 + 7;

ll a[MAXN];
bool vis[MAXN];

map<int, vector<int>> change;
vector<int> need;
vector<vector<int>> store;
map<int, int> mapUpdates;

int main(){
    int n; cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];

    int q; cin >> q;
    int maxt = 0;
    vector<pair<int, int>> updates;
    for(int i = 0; i<q; i++){
        int k, t; cin >> k >> t;
        maxt = max(maxt, t);
        updates.emplace_back(make_pair(k, t));
    }

    set<int> tmp;
    for(auto x: updates) tmp.insert(x.second);
    for(auto x: tmp) need.emplace_back(x);
    for(int i = 0; i<need.size(); i++) mapUpdates[need[i]] = i;
    vector<int> cur;
    for(int i = 0; i<n; i++) cur.emplace_back(0);
    cur[0] = 1;
    int times = 0;
    for(int x: need){
        while(times<x){
            vector<int> nxt;
            nxt.resize(n);
            for(int i = 0; i<n; i++) nxt[i] = cur[i] + cur[(i-1+n)%n];
            for(int i = 0; i<n; i++) if(nxt[i]>=MOD) nxt[i] -= MOD;
            swap(nxt, cur);
            times++;
        }
        store.emplace_back(cur);
    }

    for(auto u: updates){
        int k = u.first;
        int t = mapUpdates[u.second];
        for(int i = 0; i<n; i++) vis[i] = false;
        vector<ll> nxt;
        nxt.resize(n);
        vector<ll> use;

        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            vector<int> v;
            int cval = i;
            while(!vis[cval]){
                vis[cval] = true;
                v.emplace_back(cval);
                cval += k;
                if(cval>=n) cval-=n;
            }

            if(use.size() == 0){
                use.resize(v.size());
                for(int j = 0; j<n; j++){
                    int idx = j%use.size();
                    use[idx] += store[t][j];
                    if(use[idx]>=MOD) use[idx] -= MOD;
                }
            }

            for(int j = 0; j<v.size(); j++){
                for(int l = 0; l<v.size(); l++){
                    int idx = (j + l)%v.size();
                    nxt[v[idx]] += (use[l]*a[v[j]])%MOD;
                    if(nxt[v[idx]]>=MOD) nxt[v[idx]] -= MOD;
                }
            }
        }

        for(int i = 0; i<n; i++) a[i] = nxt[i];
    }

    for(int i = 0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
