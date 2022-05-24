//int max = 2 147 483 647 (2^31-1)
//ll max = 9 223 372 036 854 775 807 (2^63-1)
#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

//Fast input and output
void fast_io(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);}

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<< (ostream &cout, pair<A,B> const &p)
{return cout << "(" << p.f << ", " << p.s << ")";}
template<typename A> ostream& operator<< (ostream &cout, vector<A> const&v)
{cout << "["; forn(i,(int)v.size()){ if (i) cout << ", "; cout << v[i];} return cout << "]";}

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
//use uniform_int_distribution<int>(a, b)(rng) if you want [a, b].


int main(){
  fast_io();
  int n,q; cin >> n >> q;
  vl a(n),b(n);
  forn(i,n) cin >> a[i];
  forn(i,n) cin >> b[i];
  vi par(n), leader(n), cab(n);
  vl tim(n,(ll)MOD*MOD);

  /*dist[i] is the distance that car i will have 
  traveled before and up to the collision*/
  iota(par.begin(), par.end(), 0);
  iota(leader.begin(), leader.end(), 0);
  iota(cab.begin(), cab.end(), 0);
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  //(time that i will collide, i)
  forn(i,n-1){
    if(b[i]>b[i+1]){
      pq.push(mp((a[i+1]-a[i]-2)/(b[i]-b[i+1])+1,i));}
  }
  while(pq.size()>0){
    pair<ll,int> k=pq.top(); pq.pop();
    if(par[k.s]!=k.s) continue;
    if(cab[k.s]>0){
      int x=cab[k.s]-1,y=leader[k.s+1]; 
      //predicting if/when x will bump into y
      if(b[x]>b[y]){
        pq.push(mp((a[y]-a[x]-(y-x)-1)/(b[x]-b[y])+1,x));}
    }
    leader[cab[k.s]]=leader[k.s+1];
    cab[leader[k.s+1]]=cab[k.s];
    par[k.s]=leader[k.s+1];
    tim[k.s]=k.f;
  }
  int k=1;
  while((1<<k)<=n) k++;
  vector<vector<pair<int,ll>>>anc(n,vector<pair<int,ll>>(k));
  // anc[i][j] is i's 2^jth parent (1st parent is parent)
  forn(j,k) forn(i,n){
    if(j==0) anc[i][j]=mp(par[i],tim[i]);
    else anc[i][j]=mp(anc[anc[i][j-1].f][j-1].f,max(anc[i][j-1].s,anc[anc[i][j-1].f][j-1].s));
  }
  ll pans=0;
  forn(qu, q){
    ll x,y; cin >> x >> y;
    x=(x+pans)%n; y=(y+pans)%(MOD-7)+1;
    // cout << x << " " << y << endl;
    int z=x;
    for(int i=k-1;i>=0;i--){
      if(anc[z][i].s<=y) z=anc[z][i].f;
    }
    pans=a[z]+b[z]*y-(z-x);
    cout << pans << "\n";
  }
}
//code by DanTheMan
//but debugged by gabe