/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

char a[1000];

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];

        if (a[i] == 'B' && i > 0 && a[i-1] != 'B')
            a[i] = (a[i-1] == 'U' ? 'D' : 'U');
    }

    for (int i=n-1; i>=0; i--) {
        if (a[i] == 'B')
            a[i] = (i == n - 1 ? 'U' : a[i+1] == 'U' ? 'D' : 'U');
    }

    for (int i=0; i<n; i++)
        cout << a[i] << " \n"[i==n-1];

    return 0;
}
