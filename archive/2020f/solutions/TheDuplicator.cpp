#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// #include "testlib.h"

using namespace std;

typedef long long ll;
struct chash {
    int operator()(pair<int, int> x) const { return x.first* 31 + x.second; }
};


void solve(int argc, char* argv[], int tc = 0) {
	ll n;
	cin >> n;
	int a[n], b[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	ll pairs = n * (n - 1) / 2;
	
	map<int, int> c1;
	for (int i = 0; i < n; i++) pairs -= c1[a[i]]++;
	map<int, int> c2;
	for (int i = 0; i < n; i++) pairs -= c2[b[i]]++;
	
	map<pair<int, int>, int> c3;
	for (int i = 0; i < n; i++) pairs += c3[{a[i], b[i]}]++;
	
	cout << pairs << '\n';
}
 
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(argc, argv, t);
} 