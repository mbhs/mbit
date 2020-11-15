#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<long long> pref(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> pref[i];
        pref[i] += pref[i-1];
    }

    auto query = [&] (int l, int r) {
        return pref[r] - pref[l-1];
    };

    while (q--) {
        int x, k;
        cin >> x >> k;
        int y = x + 2 * k - 1, l = 0, r = k;
        long long tot = query(x, y);
        while (l < r) {
            int m = (l + r) / 2;
            long long cur = query(x, x + k - m - 1) + query(y - m + 1, y);
            if (cur <= tot - cur)
                r = m;
            else
                l = m + 1;
        }
        cout << min(abs(tot - 2 * (query(x, x + k - l - 1) + query(y - l + 1, y))),
                    l == 0 ? LLONG_MAX : abs(tot - 2 * (query(x, x + k - l) + query(y - l + 2, y)))) << "\n";
    }

    return 0;
}