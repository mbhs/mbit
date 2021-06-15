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

template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    template<typename S> Point(const Point<S> &p) : x((T) p.x), y((T) p.y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    Point& operator += (const Point &other) {return *this = *this + other;}
    Point& operator -= (const Point &other) {return *this = *this - other;}
    Point& operator *= (T c) {return *this = *this * c;}
    Point& operator /= (T c) {return *this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrt(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return abs(atan2(cross(a, b), dot(a, b)));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
};
typedef Point<int> P;

bool equal(const P &a, const P &b) {
    return (long long) a.x * b.y == (long long) a.y * b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<P> p(n), q(n);
        for (int i=0; i<n; i++)
            cin >> p[i].x >> p[i].y;
        for (int i=0; i<n; i++)
            cin >> q[i].x >> q[i].y;

        rotate(p.begin(), min_element(p.begin(), p.end()), p.end());
        rotate(q.begin(), min_element(q.begin(), q.end()), q.end());
        P fact;
        bool ok = true;
        for (int i=1; i<n; i++) {
            P v = p[i] - p[i-1], w = q[i] - q[i-1];
            if (i == 1)
                fact = v.x != 0 || w.x != 0 ? P(v.x, w.x) : P(v.y, w.y);
            if (!equal(P(v.x, w.x), fact) || !equal(P(v.y, w.y), fact)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
