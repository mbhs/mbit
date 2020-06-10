/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    string s;
    cin >> n >> s >> x >> y;

    int sx = 0, sy = 0;
    for (char c : s) {
        if (c == 'R') sx++;
        else if (c == 'L') sx--;
        else if (c == 'U') sy++;
        else sy--;
    }

    cout << abs(sx - x) + abs(sy - y) << "\n";

    return 0;
}
