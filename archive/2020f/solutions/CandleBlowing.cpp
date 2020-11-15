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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

const int MAX = 1005;

bool vis[MAX][MAX];
vector<pair<int, int>> lit[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, b;
    string s;
    cin >> n >> m >> k >> b >> s;
    for (int i=0; i<k; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        vis[r][c] = true;
        for (int j=0; j<4; j++)
            lit[j].emplace_back(r, c);
    }

    int ret = k;
    for (char ch : s) {
        int d = ch == 'N' ? 0 : ch == 'E' ? 1 : ch == 'S' ? 2 : 3;
        vector<pair<int, int>> add;
        for (auto [r, c] : lit[d]) {
            int nr = r + dr[d], nc = c + dc[d];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && !vis[nr][nc]) {
                ret++;
                vis[nr][nc] = true;
                add.emplace_back(nr, nc);
            }
        }
        lit[d].clear();
        for (int j=0; j<4; j++)
            lit[j].insert(lit[j].end(), add.begin(), add.end());
        cout << ret << "\n";
    }

    return 0;
}