/* 
Deleting Edges
u -> u_in, u_out
merge restricted nodes
separate subtrees
DFS tree sol on each
*/
#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;
 
const int N=200002;
int n, m, r;
vector<pii> adj[4*N];
int col[4*N];
map<int, bool> mp;
vector<pii> ans;
 
int dfs(int x, int par){
    col[x]=2;
    vi free;
    for(auto p:adj[x]){
        int e=p.f, k=p.s;
        if(k==par) continue;
        if(col[k]==0){
            int ret=dfs(k, x);
            if(ret) ans.pb({e, ret});
            else free.pb(e);
        }
        else if(col[k]==1) continue;
        else if(col[k]==2) free.pb(e);
    }
    for(int i=0; i+1<sz(free); i+=2){
        ans.pb({free[i], free[i+1]});
    }
    col[x]=1;
    return sz(free)&1?free.back():0;
}
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
 
  cin >> n >> m >> r;
  rep(i,1,2*n+1) mp[i]=1;
 
  rep(i,1,r){
    int u; string s; cin >> u >> s;
    if(s=="in") mp[2*u]=0;
    else mp[2*u+1]=0;
  }
 
  int cnt=2*n+2;
  rep(i,1,m){
    int u,v; cin >> u >> v;
    u=2*u+1;
    v=2*v;
    if(mp[u] && mp[v]) continue;
    if(mp[u]){
        adj[v].pb({i, cnt});
        adj[cnt].pb({i, v});
        cnt++;
    }
    else if(mp[v]){
        adj[u].pb({i, cnt});
        adj[cnt].pb({i, u});
        cnt++;
    }
    else{
        adj[u].pb({i, v});
        adj[v].pb({i, u});
    }
  }
 
  rep(i,1,cnt){
    if(col[i]) continue;
    dfs(i, 0);
  }
 
  cout << sz(ans) << nl;
  for(pii p:ans) cout << p.f << " " << p.s << nl;
}

