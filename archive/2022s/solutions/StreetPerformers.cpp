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
  int n,k; cin >> n >> k;
  vi a(n), dp(n);
  forn(i,n) cin >> a[i];
  multiset<int> s;
  int pnt=n-1;
  for(int i=n-1;i>=0;i--){
  	s.insert(a[i]);
  	while(*(--s.end())-(*s.begin())>k){
  		s.erase(s.find(a[pnt])); 
      pnt--;}
  	if(pnt==n-1) dp[i]=0;
  	else dp[i]=dp[pnt+1]+1;
  }
  forn(i,n) cout << dp[i] << " ";
}
//code by DanTheMan
