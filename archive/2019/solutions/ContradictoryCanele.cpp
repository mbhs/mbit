#include <bits/stdc++.h>

using namespace std;

long long grid[205][205];

int main() {
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  if (n % k == 0 && m % q == 0) {
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << endl;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < q; j++) {
      grid[i][j] = k * q - (i * q + j) - 1;
    }
  }
  grid[k - 1][q - 1] = -(k * q) * (k * q - 1) / 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << -grid[i % k][j % q] << " ";
    }
    cout << endl;
  }
}
