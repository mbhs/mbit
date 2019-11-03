
#include <iostream>
using namespace std;

int a[1000000][3];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  int mnx = a[0][0] - a[0][2];
  int mxx = a[0][0] + a[0][2];
  int mny = a[0][1] - a[0][2];
  int mxy = a[0][1] + a[0][2];
  for (int i = 1; i < n; i++) {
    mnx = min(mnx, a[i][0] - a[i][2]);
    mxx = max(mxx, a[i][0] + a[i][2]);
    mny = min(mny, a[i][1] - a[i][2]);
    mxy = max(mxy, a[i][1] + a[i][2]);
  }
  cout << ((long long)mxx - mnx) * ((long long)mxy - mny) << endl;
}