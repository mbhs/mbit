#include <bits/stdc++.h>

using namespace std;

// macros that make life less painful

#define f first
#define s second

using T = double; // type
using P = pair<T, T>; // point
using C = pair<P, T>; // circle
using S = pair<P, P>; // segment

// constants
const T EPS = 1e-6;
const T EPS2 = 1e-9; // this constant is needed for splitting around 2 * PI
const T PI = 4 * atan(1);

// point operations, thanks Benq for the geometry templates

int sgn(const T& a) { return (a > EPS) - (a < -EPS); }
T sq(const T& a) { return a * a; }
T norm(const P& p) { return sq(p.f) + sq(p.s); }
T abs(const P& p) { return sqrt(norm(p)); }
P conj(const P& p) { return P(p.f, -p.s); }
P dir(T ang) { return P(cos(ang), sin(ang)); }
T arg(const P& p) {
	T res = atan2(p.s, p.f);
	if (sgn(res) == -1) res += 2 * PI;
	assert(res <= 2 * PI);
	return res;
}

P operator-(const P& l) { return P(-l.f, -l.s); }
P operator+(const P& l, const P& r) { return P(l.f + r.f, l.s + r.s); }
P operator-(const P& l, const P& r) { return P(l.f - r.f, l.s - r.s); }
P operator*(const P& l, const T& r) { return P(l.f * r, l.s * r); }
P operator/(const P& l, const T& r) { return P(l.f / r, l.s / r); }
P operator*(const T& l, const P& r) { return r * l; }
P operator*(const P& l, const P& r) {
	return P(l.f * r.f - l.s * r.s, l.s * r.f + l.f * r.s); }
P operator/(const P& l, const P& r) {  return l * conj(r) / norm(r); }

T arc_length(const C& x, const P& a, const P& b) { // precondition: a and b on x
	P d = (a - x.f) / (b - x.f); return x.s * acos(d.f); }
P unit(const P& p) { return p / abs(p); }
T cross(const P& a, const P& b) { return a.f * b.s - a.s * b.f; }
T cross(const P& p, const P& a, const P& b) { return cross(a - p, b - p); }
int half(const P& x) { return x.s != 0 ? sgn(x.s) : -sgn(x.f); } // -1 if lower half, 0 if origin, 1 if upper half
bool angle_cmp(const P& a, const P& b) {
	int A = half(a), B = half(b);
	return A == B ? cross(a,b) > 0 : A < B; }

const T INF = 2e18;

template <class T> struct FenwickTree {
	std::vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.assign(n, 0);
	}

	void init(std::vector<T>& a) {
		n = (int)a.size();
		a.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1))
			fwt[idx] += delta;
	}

	void range_update(int l, int r, T val) {
		if (l > r) return;
		add(l, val);
		add(r + 1, -val);
	}

	T point_query(int p) {
		return query(0, p);
	}
};

template <class C, bool directed> struct Dijkstra {
	int SZ; vector<C> dist;
	vector<vector<pair<int, C>>> adj;

	void init(int _SZ) {
		SZ = _SZ;
		adj.clear();
		adj.resize(SZ);
	}

	void ae(int u, int v, C cost) {
		adj[u].emplace_back(v, cost);
		if (!directed) adj[v].emplace_back(u, cost);
	}

	void gen(int st, int ed) {
		dist = vector<C>(SZ, INF);

		typedef pair<C, int> T;

		priority_queue<T, vector<T>, greater<T>> pq;

		auto ad = [&](int a, const C& b) {
			if (sgn(b - dist[a]) >= 0) return;
			pq.push({dist[a] = b, a});
		};

		ad(st, 0);
		while (!pq.empty()) {
			auto x = pq.top();
			if (x.second == ed) break;
			pq.pop();

			if (sgn(x.first - dist[x.second]) == 1) continue;

			for (auto& y: adj[x.second])
				ad(y.first, x.first + y.second);
		}
	}
};

// computing tangents

P tangent(const P& x, C y, int t = 0) {
	y.s = abs(y.s);
	if (y.s == 0) return y.f;
	T d = abs(x - y.f);
	P a = sq(y.s / d) * (x - y.f) + y.f;
	P b = sqrt(sq(d) - sq(y.s)) / d * y.s * unit(x - y.f) * dir(PI / 2);
	return t == 0 ? a + b : a - b;
}

vector<S> external(const C& x, const C& y) {
	vector<S> v;
	if (sgn(x.s - y.s) == 0) {
		P tmp = unit(x.f - y.f) * x.s * dir(PI / 2);
		v.emplace_back(x.f + tmp, y.f + tmp);
		v.emplace_back(x.f - tmp, y.f - tmp);
	} else {
		P p = (y.s * x.f - x.s * y.f) / (y.s - x.s);
		for (int i = 0; i < 2; i++)
			v.emplace_back(tangent(p, x, i), tangent(p, y, i));
	}
	return v;
}

vector<S> internal(const C& x, const C& y) { return external({x.f, -x.s}, y); }

bool on_circle(const C& x, const P& y) { return sgn(x.s - abs(x.f - y)) == 0; }

// get tangents, first point on x, second on y
vector<S> tangents(const C& x, const C& y) {
	vector<S> res;

	if (sgn(x.s) == 0 && sgn(y.s) == 0) {
		for (int i = 0; i < 4; ++i) 
			res.push_back({x.f, y.f});
		return res;
	}

	auto tmp = external(x, y);

	for (auto& s : tmp) {
		if (!on_circle(x, s.f)) swap(s.f, s.s);
		res.push_back(s);
	}

	tmp = internal(x, y);

	for (auto& s : tmp) {
		if (!on_circle(x, s.f)) swap(s.f, s.s);
		res.push_back(s);
	}

	return res;
}

// gets position in sorted vector

template <class T> int get_pos(const vector<T>& v, const T& x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

// new structs and things for bentley ottman
// 
struct Point { T x, y; int idx, code; };
struct Segment { Point p, q; int idx, code; };

T theta;

T eval(const Segment& s) {
	if (s.p.x == s.q.x) return s.p.y;
	return s.p.y + (s.q.y - s.p.y) * (theta - s.p.x) / (s.q.x - s.p.x);
}

T eval(const Segment& s, const T& theta) {
	if (s.p.x == s.q.x) return s.p.y;
	return s.p.y + (s.q.y - s.p.y) * (theta - s.p.x) / (s.q.x - s.p.x);
}

bool operator<(const Point& p1, const Point& p2) { return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; }
bool operator<(const Segment& s1, const Segment& s2) { return s1.idx != s2.idx && eval(s1) < eval(s2); }
bool operator==(const Segment& s1, const Segment& s2) { return s1.idx == s2.idx; }
bool operator!=(const Segment& s1, const Segment& s2) { return !(s1 == s2); }

// topo sort, we store variables globally to save time

vector<int> in;
list<int> todo;
vector<int> res;

vector<int> topo_sort(vector<vector<int>>& adj) {
	int n = (int)adj.size();
	in.assign(n, 0);
	res.clear();
	for (int i = 0; i < n; i++) 
		for (int j : adj[i]) 
			++in[j];
	
	for (int i = 0; i < n; i++) 
		if (!in[i]) 
			todo.push_back(i);
		
	while (!todo.empty()) {
		int x = todo.front();
		todo.pop_front();
		res.push_back(x);
		for (int nxt : adj[x]) 
			if (!(--in[nxt])) 
				todo.push_back(nxt);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin); // debugging locally
#endif
	cout << fixed << setprecision(15);

	int n; cin >> n;

	P st, ed;

	cin >> st.f >> st.s;
	cin >> ed.f >> ed.s;

	vector<C> c(n); // circles
	vector<T> cost(n); // cost of removing circles

	for (int i = 0; i < n; i++)
		cin >> c[i].f.f >> c[i].f.s >> c[i].s >> cost[i];

	// add two circles of zero radius for start and finish
	n += 2;
	c.push_back({st, 0});
	c.push_back({ed, 0});
	cost.push_back(0);
	cost.push_back(0);

	vector<pair<pair<int, int>, T>> edges; // edges for dijkstra

	vector<vector<vector<S>>> store(n, vector<vector<S>>(n)); // store tangents
	vector<vector<int>> pts(n); // points on each circle

	// index points, i is the circle it's on, j is other circle, t is tangent index
	auto bind = [&](int i, int j, int t) -> int { 
		return i * 4 * n + j * 4 + t;
	};

	// add edge from i to j of length d
	auto ae = [&](int i, int j, const T& d) {
		edges.push_back({{i, j}, d});
	};

	// precompute all tangents
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (i == j) continue;
			store[i][j] = tangents(c[i], c[j]);
			store[j][i] = store[i][j];
			for (auto& x : store[j][i]) 
				swap(x.f, x.s); 
			int sid = 0;
			for (auto& x : store[i][j]) {
				pts[i].push_back(bind(i, j, sid));
				pts[j].push_back(bind(j, i, sid));
				++sid;
			}
		}
	}

	// converts an index to the point
	auto convert = [&](int i) -> P {
		int x = i / (4 * n);
		i %= (4 * n);
		int y = i / 4;
		i %= 4;
		int z = i;
		return store[x][y][z].f;
	};


	// other endpoint of segment
	auto other = [&](int code) -> int { 
		int x = code / (4 * n);
		code %= (4 * n);
		int y = code / 4;
		code %= 4;
		int z = code;
		return bind(y, x, z);
	};

	// we declare these only once to save time

	FenwickTree<int> F; // fenwick tree 
	
	vector<int> nums; // makes reindexing nicer
	
	vector<vector<S>> segs; // store the tangents in some order
	vector<vector<int>> seg_id; // store the id of the segments
	
	vector<S> curves; // store the curves in (theta, d) space

	vector<S> use; // temp variable to store tangents
	vector<int> ids; // temp variable to hold id's
	
	vector<Point> points; // events that you have to process
	
	vector<Segment> segments; // segments that go around twice
	
	vector<vector<int>> g(n - 1); // graph of the actual segments to topo sort
	
	set<Segment> active; // active segments in angular sweep
	
	vector<int> ord; // topo order
 
	vector<T> angles; // angles for bentley ottman
	
	Point p, q, mid; // points added
	Segment s, s1, s2; // segments added
	
	vector<P> conv; // indices converted to points

	for (int i = 0; i < n; ++i) {
		for (int t : {-1, 1}) { // casework on the type of segment
			nums.clear();
			curves.clear();
			segs.clear();
			seg_id.clear();

			auto segment_to_point = [&](S x) -> P { // converts a tangent to (theta, d)
				return {arg(x.s - x.f), abs(x.s - x.f)};
			};

			// getting the tangents of the correct orientation
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				nums.push_back(j);
				use.clear();
				ids.clear();
				int sid = 0;
				for (auto& seg : store[i][j]) {
					int s = sgn(cross(seg.f, seg.s, c[i].f));
					if (s == 0) {
						if (sid < 2 && t == -1) {
							use.push_back(seg);
							ids.push_back(sid);
						} else if (sid >= 2 && t == 1) {
							use.push_back(seg);
							ids.push_back(sid);
						}
					} else {
						if (s == t) {
							use.push_back(seg);
							ids.push_back(sid);
						}
					}
					++sid;
				}

				segs.push_back(use); // tangents in the correct order
				seg_id.push_back(ids); // ids of the tangents

				curves.emplace_back(segment_to_point(use[0]), segment_to_point(use[1])); // curves
			}

			// checking if the tangents are in the right order
			for (int j = 0; j < n - 1; ++j) {
				P& a = curves[j].f;
				P& b = curves[j].s;
				if (abs(a.f - b.f) <= PI) { // if their common difference is less than PI
					if (a > b) {
						swap(curves[j].f, curves[j].s);
						swap(segs[j][0], segs[j][1]);
						swap(seg_id[j][0], seg_id[j][1]);
					}
				} else {
					if (a < b) {
						swap(curves[j].f, curves[j].s);
						swap(segs[j][0], segs[j][1]);
						swap(seg_id[j][0], seg_id[j][1]);
					}
					curves[j].s.f += 2 * PI; // padding on 2 * PI
				}
			}

			// clear previous vectors
			points.clear();
			segments.clear();

			int used = 0; // current amount used
			int subtract = 0; // the subtraction process

			// checks if segment splits across
			auto process = [&](Segment s) {
				T split = -1;
				if (sgn(s.p.x - 2 * PI) < 0 && sgn(2 * PI - s.q.x) < 0) {
					split = 2 * PI;
				} else if (sgn(s.p.x - 4 * PI) < 0 && sgn(4 * PI - s.q.x) < 0) {
					split = 4 * PI;
				}
				auto add = [&](const Segment& s) {
					points.push_back(s.p);	
					points.push_back(s.q);	
					segments.push_back(s);
				};
				if (sgn(split) == -1) {
					s.idx = s.p.idx = s.q.idx = used;
					++used;
					add(s);
				} else {
					mid.x = split - EPS2;
					mid.y = eval(s, split);
					mid.code = -1;
					s1.p = s.p; 
					s1.q = mid;
					s1.idx = s1.p.idx = s1.q.idx = used;
					++used;
					mid.x += EPS2;
					s2.p = mid; 
					s2.q = s.q;
					s2.idx = s2.p.idx = s2.q.idx = used;
					++used;
					s1.code = s2.code = s.code;
					add(s1);
					add(s2);
				}	
			};
				
			// run bentley ottman
			// go around twice to account for angles wrap around
			for (int j = 0; j < 2 * (n - 1); ++j) {
				int id = j % (n - 1);
				if (j < n - 1) {
					p.x = curves[id].f.f;
					p.y = curves[id].f.s;
					q.x = curves[id].s.f;
					q.y = curves[id].s.s;
					p.code = bind(nums[id], i, seg_id[id][0]);
					q.code = bind(nums[id], i, seg_id[id][1]);
				} else {
					p.x = curves[id].f.f + 2 * PI;
					p.y = curves[id].f.s + 2 * PI;
					q.x = curves[id].s.f + 2 * PI;
					q.y = curves[id].s.s + 2 * PI;
					p.code = bind(nums[id], i, seg_id[id][0]);
					q.code = bind(nums[id], i, seg_id[id][1]);
				}
				s.p = p;
				s.q = q;
				s.code = id;
				process(s);
				if (j == n - 2) {
					subtract = used;
				}
			}

			sort(points.begin(), points.end());
			g.clear();
			g.resize(subtract);

			active.clear();

			// actually running bentley ottman
			for (int j = 0; j < points.size(); ++j) {
				int id = points[j].idx;
				theta = points[j].x;
				auto it = active.lower_bound(segments[id]);
				if (it != active.begin()) {
					int below = prev(it)->idx;
					g[id % subtract].push_back(below % subtract);
				}
				if (it != active.end()) {
					int above = -1;
					if (*it == segments[id] && next(it) != active.end()) 
						above = next(it)->idx;
					else if (*it != segments[id]) 
						above = it->idx;
					if (above != -1)
						g[above % subtract].push_back(id % subtract);
				}
				if (it != active.end() && *it == segments[id]) 
					active.erase(it);
				else 
					active.insert(segments[id]);
			}

			ord = topo_sort(g); // topologically sort the graph
			assert(ord.size() == subtract);
			
			reverse(ord.begin(), ord.end());

			angles.clear();
		   
			auto angle_mod = [&](T x) -> T { // gets angles mod 2 * PI
				while (x >= 2 * PI) x -= 2 * PI;
				return x;
			};
			
			// angles of each segment in a vector so we can index them
			for (int j = 0; j < subtract; ++j) {
				angles.push_back(angle_mod(segments[j].p.x));
				angles.push_back(angle_mod(segments[j].q.x));
			}
		   
			sort(angles.begin(), angles.end());
			angles.erase(unique(angles.begin(), angles.end()));
		   
			int sz = (int)angles.size();
		   
			F.init(sz); // fenwick tree reset

			for (int j = 0; j < subtract; ++j) {
				int id = ord[j]; // add Dijkstra edges for each tangent
				T a1 = angle_mod(segments[id].p.x);
				T a2 = angle_mod(segments[id].q.x);
			  
				if (a2 >= 2 * PI) a2 -= 2 * PI;
			  
				int i1 = get_pos(angles, a1);
				int i2 = get_pos(angles, a2);

				int code1 = segments[id].p.code;
				int code2 = segments[id].q.code;

				int circle;

				if (code1 != -1) {
					circle = code1 / (4 * n);
				} else {
					circle = code2 / (4 * n);
				}

				int code = segments[id].code;

				T d0 = abs(segs[code][0].f - segs[code][0].s);
				T d1 = abs(segs[code][1].f - segs[code][1].s);

				if (code1 != -1) {
					ae(other(code1), code1, d0 + F.point_query(i1));
				}
				if (code2 != -1) {
					ae(other(code2), code2, d1 + F.point_query(i2));
				}

				// update for future circles
				if (i1 <= i2) 
					F.range_update(i1, i2, cost[circle]);
				else {
					F.range_update(i1, sz - 1, cost[circle]);
					F.range_update(0, i2, cost[circle]);
				}
			}
		}
	}

	int beg = 4 * n * n;
	int fin = 4 * n * n + 1;
	
	// adding the circular edges
	for (int i = 0; i < n; i++) {
		auto& circ = c[i];
		auto& v = pts[i];

		// convert indices to actual points
		conv.clear(); 
		for (auto& x : v) conv.push_back(convert(x));

		if (sgn(circ.s) == 0) { // circles of radius 0, trivial edges
			if (i == n - 2) {
				for (int j = 0; j < (int)v.size(); ++j)
					ae(beg, v[j], abs(c[i].f - conv[j]));
			} else if (i == n - 1) {
				for (int j = 0; j < (int)v.size(); ++j) 
					ae(v[j], fin, abs(c[i].f - conv[j]));
			}
		} else { // nontrivial circles  
			// angular sort and add arc length edges
			ord.resize(v.size());
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int x, int y) {
				return angle_cmp(conv[x] - c[i].f, conv[y] - c[i].f);
			});
			if ((int)v.size() > 1) {
				for (int j = 0; j < (int)ord.size(); j++) {
					auto& p1 = ord[j];
					auto& p2 = ord[(j + 1) % (int)ord.size()];
					T dist = arc_length(c[i], conv[p1], conv[p2]);
					ae(v[p1], v[p2], dist);
					ae(v[p2], v[p1], dist);
				}
			}
		}
	}

	// make Dijkstra graph and run Dijkstra

	Dijkstra<T, true> D;

	D.init(4 * n * n + 2);

	for (auto& e : edges) 
		D.ae(e.f.f, e.f.s, e.s);

	D.gen(beg, fin);

	T ans = D.dist[fin];

	cout << ans << '\n';

	return 0;
}