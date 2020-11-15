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

bool del[100001];
string s="";
string p;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  std::getline(std::cin >> std::ws, s);
  int n=sz(s);
  s='0'+s+'0';
  rep(i, 1, n-1){
    if(s[i]==s[i+1] && s[i-1]!=s[i] && s[i+2]!=s[i]) del[i]=true;
  }
  rep(i, 1, n) if(!del[i]) cout << s[i];
}