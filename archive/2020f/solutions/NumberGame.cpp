#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef vector<int> vi;

void fastIO () {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
}

int f (string s) {
	for (int i = 0; i < 10; i++) {
		for (int e = 2; e <= 3; e++) {
			if (pow(i, e) == stoi(s)) return i;
		}
	}
	return -1;
}

int main () {
	fastIO();

	string y;
	cin >> y;

	// DP
	int n = y.size();
	vi dp(n + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= min(3, i); k++) {
			if (dp[i - k] != -1 && f(y.substr(i - k, k)) != -1) {
				dp[i] = k;
				break;
			}
		}
	}

	// Work backwards to reconstruct x
	string x;
	int i = n;
	while (i) {
		if (dp[i] != -1) {
			x += f(y.substr(i - dp[i], dp[i])) + '0';
			i -= dp[i];
		} else {
			x = "-1";
			break;
		}
	}

	if (x != "-1") reverse(x.begin(), x.end());
	cout << x << '\n';
}