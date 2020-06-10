#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int& i : A) cin >> i;

	vector<ll> pre(N + 1);
	for (int i = 0; i < N; i++) pre[i + 1] = pre[i] + A[i];

	while (Q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		ll d = pre[v] - pre[u];
		cout << min(d, pre[N] - d) << endl;
	}
}