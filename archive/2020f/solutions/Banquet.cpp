#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;

int n, a;
vector<pii> vec;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
    cin >> a; if(a) vec.pb({a, i});
  }

  int cur=1;
  ll ans=0;
  trav(p, vec){
    rep(i, 1, p.first){
      ans+=abs(p.second-cur); cur++;
    }
  }

  cout << ans;
}