#include <bits/stdc++.h>
 
using namespace std;

int pt[1000005];
int dir[1000005];
int rev[1000005];
vector<int> cycle;

int main() {
  int n, k;
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
      cin >> dir[i];
      --dir[i];
      rev[dir[i]] = i;
      pt[i] = -1;
  }

  int focus = 0;
  for (int i = 0; i < n + 5; i++) {
    if (i == k) {
      cout << focus + 1 << endl;
      exit(0);
    }
    if (pt[focus] != -1) {
      k -= i + 1;
      int cyc = i - pt[focus];
      for (int j = 0; j < cyc; j++) {
        cycle.push_back(focus);
        focus = rev[focus];
      }
      reverse(cycle.begin(), cycle.end());
      cout << cycle[k % cyc] + 1 << endl;
      exit(0);
    }
    pt[focus] = i;
    focus = dir[focus];
  }
}
