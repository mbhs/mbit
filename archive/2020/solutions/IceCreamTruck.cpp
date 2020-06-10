/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    if (b < 5 * a)
        cout << n / 5 * b + n % 5 * a << "\n";
    else
        cout << n * a << "\n";

    return 0;
}
