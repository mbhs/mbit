#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    while (int(t.size()) && t.back() >= x) {
        t.pop_back();
    }
    if (int(t.size()) == 1) {
        cout << x - t[0] << '\n';
        return 0;
    }
    for (int i = 0; i < int(t.size()); i++) {
        t[i] = x - t[i];
    }
    sort(t.begin(), t.end());
    long long sum = 0;
    for (int i = 0; i < int(t.size()) - 1; i++) {
        sum += t[i];
    }
    if (t.back() <= sum) {
        sum += t.back();
        cout << (sum + 1) / 2 << '\n';
        return 0;
    }
    cout << t.back();
}
