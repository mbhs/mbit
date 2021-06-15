#include <bits/stdc++.h>

using namespace std;

const int A = 26;
const int N = 1e5 + 5;

int main() {
    string s; cin >> s;
    int n = (int)s.size();
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = s[i] - 'a';
    vector<int> dp(A, N);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[a[i]] = 0;
            if (i != n - 1) {
                dp[a[i + 1]] = min(dp[a[i + 1]], 1);
            }
        } else if (i == n - 1) {
            if (dp[a[i]] < N) {
                ans = dp[a[i]] + 1;
            }
        } else {
            if (dp[a[i]] < N) {
                dp[a[i + 1]] = min(dp[a[i + 1]], dp[a[i]] + 1);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}