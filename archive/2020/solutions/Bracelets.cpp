/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

int loc[1000001], cnt[1000000];

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        loc[a] = i;
    }
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        cnt[(i - loc[b] + n) % n]++;
    }

    cout << *max_element(cnt, cnt + n) << "\n";

    return 0;
}
