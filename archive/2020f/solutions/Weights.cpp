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
vi vec;

int main(){
//   freopen("input.txt", "r", stdin); 
//   freopen("output.txt", "w", stdout);
   cin.sync_with_stdio(0); cin.tie();
   cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
    cin >> a;
    vec.pb(a);
  }

  sort(all(vec));
  vector<ll> ps(n);
  rep(i, 0, n-1){
    ps[i]=(i?ps[i-1]:0)+vec[i];
  }

  double ans=0;
  rep(i, 0, n-1){
    ans=max(ans, abs((double)ps[i]/(i+1)-(i==n-1?0:(double)(ps[n-1]-ps[i])/(n-i-1))));
  }

  cout << setprecision(16); //fixed?
  cout << ans;
}