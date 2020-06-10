#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

vector<ll> graph[50001];
ll moves[50001];
bool visited[50001];
ll arr[1001];

int main() {

  ll n;

  cin >> n;

  f0r(i, n) {
    cin >> arr[i];
  }

  ll l, d;

  f0r(i, n - 1) {
    for (ll j = i + 1; j < n; j++) {
      if (j == i + 1 || ((arr[j] - arr[i]) * d >= l * (j - i))) {
        l = arr[j] - arr[i];
        d = j - i;
        graph[i].pb(j); 
      }
    }
  }
  
  ms(moves, 0);
  ms(visited, 0);

  //pole #, moves

  queue<pair<ll, ll>> q;
  q.push(mp(0, 0));

  while(!q.empty()) {
    auto x = q.front();
    q.pop();

    if (x.f == n-1) {
      cout << x.s + 1 << endl;
      return 0;
    }

    for(ll c: graph[x.f]) {
      if (!visited[c]) {
        q.push(mp(c, x.s + 1));
        visited[c] = 1;
      }
    }
  }
}