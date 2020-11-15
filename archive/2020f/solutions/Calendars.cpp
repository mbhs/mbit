#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void fastIO () {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
}

int main () {
	fastIO();

    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: a) {
        cin >> x;
        x--;
    }
    for (int &x: b) {
        cin >> x;
        x--;
    }
    
	// p1 and p2 store pos_A(x) and pos_B(x)
	// eq stores the rotation at which pos_A(x) = pos_C(x)
    vi p1(n), p2(n), eq(n);
    for (int i = 0; i < n; i++) p1[a[i]] = p2[b[i]] = i;
	// d = dist, del = ∆
	ll d = 0, minD = LLONG_MAX, del = 0;
	for (int i = 0; i < n; i++) {
		d += abs(p2[i] - p1[i]);
		del += p2[i] < p1[i] ? -1 : 1;
    	eq[(p1[i] - p2[i] + n) % n]++;
	}
	for (int i = 0; i < n; i++) {
		minD = min(d, minD);
		int y = b[n - 1 - i];
		d += del + p1[y] * 2 - n;
		del += (eq[(i + 1) % n] - 1) * 2;
	}

	cout << minD << '\n';
}