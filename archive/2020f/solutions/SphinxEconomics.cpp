#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator << (ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};
int main() {
    int n, r;
    cin >> n >> r;
    if (r == 2) {
        cout << pow(mi(2), n - 1);
        return 0;
    }
    deque<mi> store;
    mi num = 1;
    mi den = 1;
    mi sum = 2;
    for (int i = 0; i < r - 3; i++) {
        store.push_back(0);
    }
    store.push_back(1);
    store.push_back(1);
    for (int i = 0; i < n - 1; i++) {
        num *= 2;
        den = sum;
        store.push_back(den);
        sum += den;
        sum -= store.front();
        store.pop_front();
    }
    cout << num / den << '\n';
    return 0;
}
