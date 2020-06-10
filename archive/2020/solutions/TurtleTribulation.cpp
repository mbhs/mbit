#include <bits/stdc++.h>
using namespace std;

#define MAX 5005

int dp[MAX][MAX], st[4*MAX];

void build(int p, int l, int r, int i) {
    if (l == r) {
        st[p] = dp[i][l];
        return;
    }

    int m = (l + r) / 2;
    build(2*p, l, m, i);
    build(2*p+1, m+1, r, i);
    st[p] = min(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return INT_MAX;
    if (i <= l && r <= j)
        return st[p];

    int m = (l + r) / 2;
    return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
}

pair<int, int> p[MAX];

int main() {
    int n, z;
    double k;
    cin >> n >> z >> k;
    for (int i=0; i<n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p, p + n, [] (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });
    memset(dp, 127, sizeof(dp));

    dp[0][p[0].first] = 0;
    for (int i=1; i<n; i++) {
        build(1, 0, z, i-1);
        for (int j=0; j<=z; j++) {
            int l = max(j - (int) ((p[i-1].second - p[i].second) / k), 0), r = min(j + (int) ((p[i-1].second - p[i].second) / k), z);
            dp[i][j] = query(1, 0, z, l, r) + abs(j - p[i].first);
        }
    }

    cout << dp[n-1][p[n-1].first] << "\n";

    return 0;
}
