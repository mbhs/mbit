/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> st;
    for (int i=0; i<n; i++) {
        int w, d;
        cin >> w >> d;

        while (!st.empty() && w > 0 && st.back().second == 1 && d == 0) {
            if (w >= st.back().first) {
                w -= st.back().first;
                st.pop_back();
            } else {
                st.back().first -= w;
                w = 0;
            }
        }
        if (w > 0)
            st.emplace_back(w, d);
    }

    cout << st.size() << "\n";
    for (auto p : st)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
