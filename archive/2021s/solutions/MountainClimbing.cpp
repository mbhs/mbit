#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)

int n, mx;
int a[1002];

int main(){
    ios::sync_with_stdio(false);
   //  cin.tie(0);
   //  freopen("input.txt", "r", stdin); 
  	// freopen("output.txt", "w", stdout);

    cin >> n;
    a[0]=a[n+1]=0;
    rep(i, 1, n) cin >> a[i];
    int ans=0;
    rep(i, 1, n+1){
    	ans+=abs(a[i]-a[i-1]);
    }

    cout << ans+n;
}