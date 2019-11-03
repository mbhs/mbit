#include <bits/stdc++.h>
using namespace std;

#define MAXN 201
#define MOD 1000000007

int main() {
    int n, a[MAXN][MAXN], numPaths[MAXN][MAXN] = {1}, dp[MAXN][MAXN][MAXN];
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            a[i][j]--;
            if (i > 0) numPaths[i][j] = (numPaths[i][j] + numPaths[i-1][j]) % MOD;
            if (j > 0) numPaths[i][j] = (numPaths[i][j] + numPaths[i][j-1]) % MOD;
            for (int k=0; k<n; k++) {
                if (a[i][j] == k)
                    dp[i][j][k] = numPaths[i][j];
                else {
                    if (i > 0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
                    if (j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
                }
            }
        }

    for (int i=0; i<n; i++)
        cout << i+1 << " " << dp[n-1][n-1][i] << endl;

    return 0;
}