#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int L = 61;


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
int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int mult(int x, int y) { return 1LL * x * y % P; }
int madd(int& x, int y) { return x = add(x, y); }
int mmult(int& x, int y) { return x = mult(x, y); }
int mod(long long x) { x %= P; if (x < 0) x += P; return x; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, k; cin >> n >> k;
    vector<long long> a(L);
    for (int i = 0; i < L; ++i) a[i] = n / (1LL << i);
    for (int i = 0; i < L - 2; ++i) a[i] -= a[i + 1];
    int top = 0;
    for (int i = 0; i < L; ++i) if (a[i]) top = i;
    k = min(k, (1LL << (top + 1)) - 1);
    int ans = mod(k + 1);
    for (int i = 0; i <= top; ++i) mmult(ans, mpow(2, a[i] - 1));
    cout << ans << '\n';
    return 0;
}