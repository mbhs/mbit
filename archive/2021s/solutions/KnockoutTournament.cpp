#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

int mpow(long long b, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) {
            r *= b;
            r %= P;
        }
        b *= b;
        b %= P;
        e >>= 1;
    }
    return r;
}
int minv(long long b) { return mpow(b, P - 2); }
int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int sub(int x, int y) { x -= y; if (x < 0) x += P; return x; }
int mult(int x, int y) { return 1LL * x * y % P; }
int madd(int& x, int y) { return x = add(x, y); }
int msub(int& x, int y) { return x = sub(x, y); }
int mmult(int& x, int y) { return x = mult(x, y); }

const int N = 1e6 + 5;

int fact[N];
int ifact[N];

int C(int x, int y) {
    if (x < y) return 0;
    return mult(fact[x], mult(ifact[x - y], ifact[y]));
}

int iC(int x, int y) {
    if (x < y) return -1; // should never happen
    return mult(ifact[x], mult(fact[x - y], fact[y]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    n = (1 << n);
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = mult(fact[i - 1], i);
    ifact[N - 1] = minv(fact[N - 1]);
    for (int i = N - 2; i >= 0; --i) ifact[i] = mult(ifact[i + 1], i + 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    madd(ans, a.back());
    for (int i = 0; i < n; ++i) msub(ans, a[i]);
    int log = 0;
    while ((1 << log) < n) ++log;
    for (int i = 0; i < n; ++i) {
        int w = 0; 
        vector<int> least(log + 2);
        for (int d = log; d >= 0; --d) {
            int beat = (1 << d) - 1;
            least[d] = mult(C(i, beat), iC(n - 1, beat));
            int prob = sub(least[d], least[d + 1]);
            madd(w, mult(prob, d));
        }
        madd(ans, mult(w, a[i]));
    }
    cout << ans << '\n';
    return 0;
}