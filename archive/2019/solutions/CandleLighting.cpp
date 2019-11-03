#include <bits/stdc++.h>
using namespace std;

#define MAXN 501
#define MAXM 501

int main() {
    int n, m, a[MAXN][MAXM];
    
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    int q, prefixSum[MAXN][MAXM] = {};
    cin >> q;
    for (int i=0; i<q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        prefixSum[x1][y1]++;
        prefixSum[x1][y2+1]--;
        prefixSum[x2+1][y1]--;
        prefixSum[x2+1][y2+1]++;
    }
    int tot = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
            tot += (a[i][j] + prefixSum[i][j]) % 2;
        }
    }
    cout << tot << endl;

    return 0;
}