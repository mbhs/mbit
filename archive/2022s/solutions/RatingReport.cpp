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
  vi p(n); vi a(n);
  vector<vi>ch(n);
  for(int i=1;i<n;i++){
  	cin >> p[i]; p[i]--;
		ch[p[i]].pb(i);
  }
	forn(i,n){
		string x; cin >> x;
		if(x=="min") a[i]=-1;
		else if(x=="max") a[i]=-2;
		else a[i]=stoi(x);
	} //cout << a << endl; cout << ch << endl;
	int l=1,r=k+1;
	while(l+1<r){
		int m=(l+r)/2;
		vi less(n); vl dp(n); 
		//dp[i] is the minimum # of >=k's you need to have in leaves of subtree k to get r[i]>=k
		//less[i] is the # of >=k's built in to the leaves of subtree k
		function<void(int)>dfs=[&](int k){
			if(a[k]==0 or a[k]>=m) dp[k]=1;
			if(a[k]>=m) less[k]=1;
			if(a[k]>0 && a[k]<m) dp[k]=MOD;
			ll ext=0,sum=0;
			if(a[k]==-2) ext=MOD;
			for(auto c:ch[k]){
				dfs(c); less[k]+=less[c];
				if(a[k]==-1) ext+=dp[c];
				if(a[k]==-2) ext=min(ext,dp[c]-less[c]);
			}
			if(a[k]==-2) ext+=less[k];
			if(!ch[k].empty()) dp[k]=ext;
		}; dfs(0);
		//cout << m << " " << dp << endl;
		if(dp[0]<=k-m+1) l=m;
		else r=m;
	}
	cout << l << "\n";
}
//code by DanTheMan
