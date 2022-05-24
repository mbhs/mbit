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

struct sparsetable{
  int n,k;
  vector<vl>lmin,lmax;

  void init(int p){
    n=p; k=33-__builtin_clz(n);
    lmin=vector<vl>(n,vl(k));
    lmax=vector<vl>(n,vl(k));
  }

  void build(vl &a){
    forn(i,k) forn(j,n){
      if(i==0){
        lmin[j][i]=lmax[j][i]=a[j];
        continue;}
      if(j+(1<<(i-1))>=n){
        lmin[j][i]=lmin[j][i-1];
        lmax[j][i]=lmax[j][i-1];
        continue;}
      lmin[j][i]=min(lmin[j][i-1],lmin[j+(1<<(i-1))][i-1]);
      lmax[j][i]=max(lmax[j][i-1],lmax[j+(1<<(i-1))][i-1]);
    }
  }

  ll find_min(int x, int y){
    int j = 31-__builtin_clz(y-x);
    return min(lmin[x][j], lmin[y-(1<<j)][j]);
  }

  ll find_max(int x, int y){
    int j = 31-__builtin_clz(y-x);
    return max(lmax[x][j], lmax[y-(1<<j)][j]);
  }
};

int main(){
  fast_io();
  int n; cin >> n;
  vl a(n+2);
  a[0]=-(ll)MOD*MOD; a[n+1]=(ll)MOD*MOD;
  forn(i,n) cin >> a[i+1];
  vl p(n+1),q(n+1);
  forn(i,n+1) p[i]=a[i+1]-2*a[i];
  forn(i,n+1) q[i]=2*a[i+1]-a[i];
  sparsetable st; st.init(n+1); st.build(p);
  sparsetable st2; st2.init(n+1); st2.build(q);
	forn(i,n){
		int x=i,y=i;
		ll ans=0;
		while(y>0 or x<n-1){
			int l=x-1,r=n-1; 
			//want to find the smallest index m such that a[m+1]-2*a[m]>-a[y-1]
			//equivalent to smallest m such that st.find_min(x,m+1)>-a[y-1]
			while(l+1<r){
				int m=(l+r)/2;
				if(st.find_max(x+1,m+2)>-a[y]) r=m;
				else l=m;
			}
			x=r;
			ans+=(a[x+1]-a[i+1]);
			if(y==0 and x==n-1) continue;
			ans+=(a[x+1]-a[i+1]);
			r=y+1; l=0;
			//want to find the biggest index m such that 2*a[m]-a[m-1]>=a[x+1]
			//equivalent to finding biggest m such that q[m]>=a[x+1]
			//equivalent to biggest m such that st.find_max(m,y)>=a[x+1]
			while(l+1<r){
				int m=(l+r)/2;
				if(st2.find_max(m,y+1)>=a[x+2]) l=m;
				else r=m;
			}
			y=l;
			ans+=(a[i+1]-a[y+1]);
			if(y==0 and x==n-1) continue;
			ans+=(a[i+1]-a[y+1]);
		}
		cout << ans << "\n";
	}

}
//code by DanTheMan
