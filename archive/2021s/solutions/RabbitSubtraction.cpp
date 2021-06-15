#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int LOG = 17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<long long>> dp(n, vector<long long>(LOG));
    for (int i=0; i<n; i++)
        cin >> dp[i][0];

    for (int j=1; j<LOG; j++)
        for (int i=0; i<n; i++)
            dp[i][j] = dp[i][j-1] - dp[(i+(1<<(j-1)))%n][j-1];

    long long ret = LLONG_MIN;
    for (int i=0; i<n; i++) {
        vector<long long> all;
        int u = i;
        for (int j=LOG-1; j>=0; j--)
            if (n & (1 << j)) {
                all.push_back(dp[u][j]);
                u = (u + (1 << j)) % n;
            }
        long long cur = all.back();
        for (int j=(int)all.size()-2; j>=0; j--)
            cur = all[j] - cur;
        ret = max(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}
