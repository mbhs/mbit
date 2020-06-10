/**
 * Author: Maxwell Zhang
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, lazy = 0, pref[5], suff[5], ans[5];

    void leaf(int val) {
        pref[val] = suff[val] = ans[val] = 1;
    }

    void Merge(Node &a, Node &b) {
        for (int i=0; i<=4; i++) {
            pref[i] = a.pref[i] + (a.pref[i] == a.r - a.l + 1 ? b.pref[i] : 0);
            suff[i] = b.suff[i] + (b.suff[i] == b.r - b.l + 1 ? a.suff[i] : 0);
            ans[i] = max({a.ans[i], b.ans[i], a.suff[i] + b.pref[i]});
        }
    }

    void push(int val) {
        lazy += val;
    }

    void apply() {
        if (lazy > 0) {
            for (int i=4; i>=lazy; i--) {
                pref[i] = pref[i-lazy];
                suff[i] = suff[i-lazy];
                ans[i] = ans[i-lazy];
                pref[i-lazy] = suff[i-lazy] = ans[i-lazy] = 0;
            }
        } else {
            lazy = -lazy;
            for (int i=0; i<=4-lazy; i++) {
                pref[i] = pref[i+lazy];
                suff[i] = suff[i+lazy];
                ans[i] = ans[i+lazy];
                pref[i+lazy] = suff[i+lazy] = ans[i+lazy] = 0;
            }
        }
        lazy = 0;
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(const vector<int> &_a) : n(_a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }

        push(p);

        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, i, j, val);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i=0; i<4; i++) {
        int m;
        cin >> m;
        while (m--) {
            int l, r;
            cin >> l >> r;

            a[l]++;
            if (r < n)
                a[r+1]--;
        }
    }
    for (int i=1; i<=n; i++)
        a[i] += a[i-1];

    SegmentTree st(a);

    int q;
    cin >> q;
    while (q--) {
        int id, type, l, r;
        cin >> id >> type >> l >> r;

        if (type == 0)
            st.update(l, r, 1);
        else
            st.update(l, r, -1);

        cout << st.st[1].ans[0] << "\n";
    }

    return 0;
}
