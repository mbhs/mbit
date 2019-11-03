#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int ret = 1;
    for (int i=0; i<n; i++)
        if (a[i] != b[i])
            ret *= 2;

    cout << ret << endl;

    return 0;
}