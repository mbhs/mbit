#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int it1 = 0;
    int it2 = 0;
    while (it1 != n) {
        ll run = a[it1];
        while (it2 != n - 1 && a[it2 + 1] - a[it2] <= k) {
            it2++;
            run += a[it2];
        }
        ans = max(ans, run);
        it1 = ++it2;
    }
    cout << ans << '\n';
    return 0;
}