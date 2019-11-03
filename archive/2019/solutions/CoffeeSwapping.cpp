#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int main() {
    int n, a[2*MAXN];
    pair<int, int> b[2*MAXN];
    cin >> n;
    for (int i=0; i<2*n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }

    sort(b, b + 2 * n);
    unordered_map<int, int> mp;
    for (int i=0; i<2*n; i++)
        mp.insert(make_pair(b[i].first, i));

    int ret = 0;
    for (int i=0; i<n; i++) {
        int pos = 2 * n - mp[a[2*i]] - 1;
        if (b[pos].second != 2 * i + 1) {
            ret++;
            int tmp = a[2*i+1];
            swap(a[b[pos].second], a[2*i+1]);
            swap(b[mp[tmp]].second, b[pos].second);
        }
    }

    cout << ret << endl;

    return 0;
}
