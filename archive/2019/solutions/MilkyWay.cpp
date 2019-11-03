#include <bits/stdc++.h>

using namespace std;

int ar[105];
int ans = 0;

vector<pair<int, int> > edges[105];
int memo[105][105];

int main() {
  int n, m, a, b, c;
  cin >> n >> m >> c >> a >> b;
  --a; --b;
  for (int i = 0; i < n; i++)
    cin >> ar[i];
    
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    edges[x].push_back(make_pair(y, -z));
    edges[y].push_back(make_pair(x, -z));
  }
  
  for (int i = 0; i < n; i++)
    edges[i].push_back(make_pair(i, ar[i]));

  for (int i = 0; i <= c; i++) 
    for (int j = 0; j < n; j++) 
      memo[i][j] = -1;

  queue<pair<pair<int, int>, int> > q; /* cost, node, dist */
  q.push(make_pair(make_pair(0, a), 0));
  while (!q.empty()) {
    pair<pair<int, int>, int> x = q.front();
    q.pop();

    int cost = x.first.first, v = x.first.second, dist = x.second;

    if (memo[cost][v] != -1) 
      continue;

    memo[cost][v] = dist;
    for (pair<int, int> next: edges[v]) {
      int ncost = min(c, cost + next.second), nnode = next.first;
      if (ncost >= 0 && memo[ncost][nnode] == -1) 
        q.push(make_pair(make_pair(ncost, nnode), dist + 1));
    }
  }

  ans = 1e9;
  for (int i = 0; i <= c; i++)
    if (memo[i][b] != -1) ans = min(ans, memo[i][b]);

  cout << ans << endl;
}