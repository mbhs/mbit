#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    const ld INF = 1e15;
    const ld EPS = 1e-7;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ld>>> bots(n);
    for (int i = 0; i < m; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        l--, r--;
        bots[l].emplace_back(r, w);
    }
    for (int i = 0; i < n; i++) {
        sort(bots[i].begin(), bots[i].end());
    }
    auto check_low = [&](ld x) -> bool {
        priority_queue<array<ld, 3>, deque<array<ld, 3>>, greater<array<ld, 3>>> pq;
        for (int i = 0; i < n; i++) {
            for (auto b: bots[i]) {
                array<ld, 3> bt;
                bt[1] = i;
                bt[0] = b.first;
                bt[2] = b.second;
                pq.push(bt);
            }
            ld cur = x;
            while (abs(cur) > EPS) {
                if ((int) pq.size() == 0) {
                    return false;
                }
                auto beg = pq.top();
                pq.pop();
                if (beg[1] > i) {
                    return false;
                } else if (beg[0] < i) {
                    continue;
                } else {
                    if (beg[2] <= cur) {
                        cur -= beg[2];
                    } else {
                        beg[2] -= cur;
                        pq.push(beg);
                        cur = 0;
                    }
                }
            }
        }
        return true;
    };
    auto check_high = [&](ld x) -> bool {
        priority_queue<array<ld, 3>, deque<array<ld, 3>>, greater<array<ld, 3>>> pq;
        int cnt = m;
        for (int i = 0; i < n; i++) {
            for (auto b: bots[i]) {
                array<ld, 3> bt;
                bt[1] = i;
                bt[0] = b.first;
                bt[2] = b.second;
                pq.push(bt);
            }
            ld cur = x;
            while (abs(cur) > EPS) {
                if (cnt == 0) {
                    return true;
                }
                if ((int) pq.size() == 0) {
                    break;
                }
                auto beg = pq.top();
                pq.pop();
                cnt--;
                if(beg[1] > i) {
                    pq.push(beg);
                    cnt++;
                    break;
                } else if (beg[0] < i) {
                    if (abs(beg[2]) > EPS) {
                        return false;
                    }
                } else {
                    if (beg[2] <= cur) {
                        cur -= beg[2];
                    } else {
                        beg[2] -= cur;
                        cur = 0;
                        pq.push(beg);
                        cnt++;
                    }
                }
            }
        }
        return false;
    };
    ld lo = 0;
    ld hi = INF;
    while (abs(hi - lo) > EPS) {
        ld mid = (lo + hi) / 2;
        if (check_low(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    ld low_bound = (lo + hi) / 2;
    lo = 0;
    hi = INF;
    while (abs(hi - lo) > EPS) {
        ld mid = (lo + hi) / 2;
        if (check_high(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    ld high_bound = (lo + hi) / 2;
    cout << fixed << setprecision(30);
    cout << low_bound / high_bound << '\n';
    return 0;
}