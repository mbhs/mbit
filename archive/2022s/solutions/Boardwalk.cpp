/*
Equalize Array
difference array on circular array
mcmf
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
 
// copied from ?
// works for negative edges
template <class C, class F>
struct MCMF {
  static constexpr F eps = (F) 1e-9;
  struct Edge {
    int v, inv;
    F cap, flow;
    C cost;
    Edge(int v, C cost, F cap, int inv) : 
      v(v), cost(cost), cap(cap), flow(0), inv(inv){}
  };
 
  int s, t, n, m = 0;
  vector< vector<Edge> > g;
  vector<C> cost;
  vi state, path, from;
 
  MCMF(int n, int ss = -1, int tt = -1):
    n(n), g(n + 5), cost(n + 5), state(n + 5), 
    path(n + 5), from(n + 5) {
    s = ss == -1 ? n + 1 : ss;
    t = tt == -1 ? n + 2 : tt;
  }
 
  void add(int u, int v, F cap, C cost) {
    g[u].pb(Edge(v, cost, cap, sz(g[v])));
    g[v].pb(Edge(u, -cost, 0, sz(g[u]) - 1));
    m += 2;
  }
 
  bool bfs() {
    fill(all(state), 2);
    fill(all(cost), numeric_limits<C>::max());
    deque<int> qu;
    qu.push_back(s);
    state[s] = 1, cost[s] = 0;
    while (sz(qu)) {
      int u = qu.front(); qu.pop_front();
      state[u] = 0;
      for (Edge &e : g[u]) if (e.cap - e.flow > eps)
        if (cost[u] + e.cost < cost[e.v]) {
          cost[e.v] = cost[u] + e.cost;
          path[e.v] = u;
          from[e.v] = g[e.v][e.inv].inv;
          if (state[e.v] == 0 || (sz(qu) && cost[qu.front()] > cost[e.v]))
            qu.push_front(e.v);
          else if (state[e.v] == 2)
            qu.push_back(e.v);
          state[e.v] = 1;
        }
    }
    return cost[t] != numeric_limits<C>::max();
  }
 
  pair<C, F> minCostFlow() {
    C cost = 0; F flow = 0;
    while (bfs()) {
      F nflow = numeric_limits<F>::max();
      for (int u, v = t; v != s; v = u) {
        u = path[v];
        Edge &e = g[u][from[v]];
        nflow = min(nflow, e.cap - e.flow);
      }
      for (int u, v = t; v != s; v = u) {
        u = path[v];
        g[u][from[v]].flow += nflow;
        g[v][g[u][from[v]].inv].flow -= nflow;
        cost += g[u][from[v]].cost * nflow;
      }
      flow += nflow;
    }
    return make_pair(cost, flow);
  }
};
 
const int N=201;
int n, k;
int a[N], d[N];
 
int main(){
  cin.tie(0)->sync_with_stdio(0);
 
  cin >> n >> k;
  MCMF<ll, ll> mf(n+2, 0, n+1);
  rep(i,1,n) cin >> a[i];
  a[0]=a[n];
  ll sumd=0;
  rep(i,1,n){
    d[i]=a[i]-a[i-1];
  }
  int maxC=0;
  rep(i,1,k){
    int l,r,c;
    cin >> l >> r >> c;
    maxC=max(maxC, c);
    mf.add(l, (r==n?1:r+1), 1e18, c);
  }
  ll need=0;
  rep(i,1,n){
    if(d[i]<0) mf.add(0, i, -d[i], 0);
    if(d[i]>0) mf.add(i, n+1, d[i], 0), need+=d[i], sumd+=d[i];
  }
  auto p=mf.minCostFlow();
  assert(p.f<=sumd*n*maxC);
  if(p.s!=need) cout << -1;
  else cout << p.f;
}

