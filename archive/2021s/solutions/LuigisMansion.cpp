#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Line {
    mutable long long a, b, lst;

    long long eval(long long x) {
        return a * x + b;
    }

    bool operator < (const Line& y) const {
        return a < y.a;
    }

    long long floor_div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    long long bet(const Line& y) {
        assert(a <= y.a);
        return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);
    }
};

struct ConvexHullDeque : std::deque<Line> {
    void add_back(Line L) {
        while (true) {
            auto a = back();
            pop_back();
            a.lst = a.bet(L);
            if (size() && back().lst >= a.lst) {
                continue;
            }
            push_back(a);
            break;
        }
        L.lst = INF;
        push_back(L);
    }

    void add_front(Line L) {
        while (true) {
            if (!size()) {
                L.lst = INF;
                break;
            }
            if ((L.lst = L.bet(front())) >= front().lst) {
                pop_front();
            } else {
                break;
            }
        }
        push_front(L);
    }

    void add(long long a, long long b) {
        // comment this out for max
        a = -a; b = -b;
        if (!size() || a <= front().a) {
            add_front({a, b, 0});
        } else {
            assert(a >= back().a);
            add_back({a, b, 0});
        }
    }

    int ord = 1; // 1 = increasing, -1 = decreasing

    long long query(long long x) {
        // flip negatives for max
        assert(ord);
        if (ord == 1) {
            while (front().lst < x) {
                pop_front();
            }
            return -front().eval(x);
        } else {
            while (size() > 1 && prev(prev(end()))-> lst >= x) {
                pop_back();
            }
            return -back().eval(x);
        }
    }
};

const int N = 5005;

int n; 

long long a[N];
long long p[N];
long long dp[N][N];

ConvexHullDeque C[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    long long den = 0;
    
    cin >> n >> den;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    
    long long num = 0;
    
    for (int i = 1; i <= n; i++) 
        num += a[i] * i * 3;
    
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 2 * i * (den - p[i]);
        C[i].add(-2 * p[0], dp[0][i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = C[i].query(j) + 2 * j * (den - p[i] - p[j]);
            dp[i][j] = min(dp[i][j], C[j].query(i) + 2 * i * (den - p[i] - p[j]));
            C[j].add(-2 * p[i], dp[i][j]);
        }
    }

    num += dp[n][n];

    long long g = __gcd(num, den);

    num /= g;
    den /= g;

    cout << num << "/" << den << '\n';

    return 0;
}