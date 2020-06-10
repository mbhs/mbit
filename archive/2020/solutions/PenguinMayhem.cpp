#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const long double PI = 4*atan(1);

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define resz resize
#define ins insert

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...);
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }

	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);

	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
		pr(t); pr(ts...);
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}");
	}
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}");
	}

	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
	}

	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

typedef decay<decltype(MOD)>::type T;
struct mi {
	T val;
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const mi& a) {
		// return os << a.val; }
	friend void pr(const mi& a) { pr(a.val); }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }

	friend bool operator==(const mi& a, const mi& b) {
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.val < b.val; }

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) {
		assert(a != 0); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};

typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

const int MAX = 1e3 + 5;

struct frac{
    ll num; ll den;
    frac(){ num = 0; den = 1; }
    frac(ll a, ll b){
        if(a<0&&b<0)a*=-1, b*=-1;
        if(a == 0 && b == 0) num = a, den = b;
        else if(a == 0) num = 0, den = 1;
        else if(b == 0) num = a/abs(a), den = 0;
        else{
            ll g = __gcd(a, b);
            a/=g; b/=g;
            if(b<0) a *= -1, b *= -1;
            num = a; den = b;
        }
    }
    ld value(){ assert(den != 0); return ((ld) num)/den; }
    int sign(){
        if(num == 0) return 0;
        if(num>0) return 1;
        return -1;
    }

};
string to_string(frac f){
        return to_string((int) f.num) + "/" + to_string((int) f.den);
}
typedef pair<frac, frac> pf;

pl st[MAX];
pl v[MAX];
ll w, h;
frac bad;

pf get(pl& p, pl& r, pl& q, pl& s, bool flip){
    if(!flip){
        frac le = frac(p.f - q.f, s.f - r.f);
        frac ri = frac(w, s.f - r.f);
        return mp(le, ri);
    }
    frac le = frac(p.s - q.s, s.s - r.s);
    frac ri = frac(h, s.s - r.s);
    return mp(le, ri);
}

inline ll LCM(ll a, ll b){ return a/__gcd(a, b)*b; }

pl euclid(ll a, ll b) {
	if (!b) return {1,0};
	pl p = euclid(b,a%b);
	return {p.s,p.f-a/b*p.s};
}

pl CRT(pl a, pl b) {
	if (a.s < b.s) swap(a,b);
	ll x,y; tie(x,y) = euclid(a.s,b.s);
	ll g = a.s*x+b.s*y, l = a.s/g*b.s;
	if ((b.f-a.f)%g) return {-1,-1};

	x = (b.f-a.f)%b.s*x%b.s/g*a.s+a.f;
	return {x+(x<0)*l,l};
}

pf simplify(pf p){
    if(p.s.num<0) p.s.num *= -1;
    ll b = p.f.den; ll d = p.s.den;
    ll mult = LCM(b, d);
    ll a = p.f.num; ll c = p.s.num;
    a = mult/b*a; c = mult/d*c;
    if(c<0) c*= -1;
    a = (a%c + c)%c;
    return mp(frac(a, mult), frac(c, mult));
}

pf comb(pf x, pf y){
    ll mult = LCM(LCM(x.f.den, x.s.den), LCM(y.f.den, y.s.den));
    ll a = mult/x.f.den*x.f.num; ll b = mult/x.s.den*x.s.num;
    ll c = mult/y.f.den*y.f.num; ll d = mult/y.s.den*y.s.num;
    if(b<0) b *= -1;
    if(d<0) d *= -1;
    a = (a%b + b)%b; c = (c%d + d)%d;
    pl crt = CRT(mp(a, b), mp(c, d));
    if(crt.f == -1) return mp(bad, bad);
    return mp(frac(crt.f, mult), frac(crt.s, mult));
}

pf solve(int a, int b){
    auto p = st[a]; auto r = v[a]; auto q = st[b]; auto s = v[b];
    if(r == s){
        if(p != q) return mp(bad, bad);
        assert(false); /// this means they are the same asteroid
    }
    else if(r.f == s.f){
        if(p.f != q.f) return mp(bad, bad);
        return simplify(get(p, r, q, s, true));
    }
    else if(r.s == s.s){
        if(p.s != q.s) return mp(bad, bad);
        return simplify(get(p, r, q, s, false));
    }
    else return comb(get(p, r, q, s, true), get(p, r, q, s, false));

}
int main(){
    setIO("");
    int n; re(n);
    bad = frac(-1, 1);
    re(h, w);
    f0r(i, n) re(st[i].f, st[i].s), re(v[i].f, v[i].s);
    ld t; re(t);
    ll ans = 0;
    f0r(i, n){
        f1r(j, i+1, n){
            if(i==j) continue;
            auto res = solve(i, j);
            if(res.f.value() == -1) continue;
            ld x = (res.f.value()); ld y = (res.s.value());
//            ps(to_string(res.f), to_string(res.s));
            if(x>t) continue;
            ans += floor((t-x)/y +1);
        }
    }
    ps(ans);
    return 0;
}
