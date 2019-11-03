#include <bits/stdc++.h>
using namespace std;

long long h[100000];

int main() {
    long long n, a, b, rightSum = 0;
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        cin >> h[i];
        rightSum += h[i];
    }

    long long ret = LLONG_MAX, leftSum = 0;
    sort(h, h + n);
    for (int i=0; i<n; i++) {
        ret = min(ret, a * (i * h[i] - leftSum) + b * (rightSum - (n - i) * h[i]));
        leftSum += h[i];
        rightSum -= h[i];
    }

    cout << ret << endl;

    return 0;
}
