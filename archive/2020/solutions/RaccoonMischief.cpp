/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int a[MAXN];
vector<pair<int, int>> add[MAXN], rem[MAXN];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        add[l].emplace_back(i, x);
        rem[r].emplace_back(i, x);
    }

    set<pair<int, int>> st;
    for (int i=0; i<n; i++) {
        for (auto p : add[i])
            st.insert(p);

        if (st.empty())
            cout << a[i];
        else if ((st.size() % 2 == 0) ^ (a[i] == 0))
            cout << st.rbegin()->second;
        else
            cout << 0;
        cout << " \n"[i==n-1];

        for (auto p : rem[i])
            st.erase(p);
    }

    return 0;
}
