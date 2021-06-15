#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a:x)
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
template<class T> using pqg=priority_queue<T, vector<T>, greater<T>>;



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);

  string s;
  vector<string> ans;
  while(cin >> s){
    if(s[0]==toupper(s[0])){
      s[0]=tolower(s[0]);
      s[sz(s)-1]=toupper(s[sz(s)-1]);
    }
    reverse(all(s));
    ans.pb(s);
  }

  for(int i=sz(ans)-1; i>=0; i--){
    cout << ans[i] << " ";
  }
}