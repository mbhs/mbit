#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
#define nl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;

int m, n, a, id;
stack<int> temp;
stack<int> temp2;
vector<pii> ans;
vi v;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
   cin.sync_with_stdio(0); cin.tie();
   cin.exceptions(cin.failbit);

  cin >> n >> m;
  //push everything to 1
  rep(i, 1, m){
    cin >> a;
    rep(j, 1, a){
      cin >> id;
      if(i!=1){
        ans.pb({i, 1});
        temp.push(id);
      }
      else v.pb(id);
    }
    if(i==1){
      reverse(all(v));
      trav(k, v) temp.push(k);
    }
  }

  // push m's to mth, others to 2
  while(!temp.empty()){
    int x=temp.top(); temp.pop();
    if(x==m) ans.pb({1, m});
    else{
      ans.pb({1, 2});
      temp2.push(x);
    }
  }

  while(!temp2.empty()){
    int x=temp2.top(); temp2.pop();
    if(x==2){
      ans.pb({2, m});
      temp.push(x);
    }
    else{
      ans.pb({2, x});
    }
  }

  while(!temp.empty()){
    int x=temp.top(); temp.pop();
    ans.pb({m, 2});
  }
  
  cout << sz(ans) << nl;
  trav(k, ans) cout << k.first << " " << k.second << nl;
}