#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;

  cin >> n;

  int num_p = 0, num_b = 0;
  double cp_x, cp_y, cb_x, cb_y;
  cp_x = cp_y = cb_x = cb_y = 0;

  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < n; j++) {
      if(s[j] == 'p') {
        cp_x += j;
        cp_y += i;
        num_p++;
      } else if(s[j] == 'b'){
        cb_x += j;
        cb_y += i;
        num_b++;
      }
    }
  }

  cp_x /= num_p;
  cp_y /= num_p;

  cb_x /= num_b;
  cb_y /= num_b;

  double diff_x = cb_x - cp_x;
  double diff_y = cb_y - cp_y;

  if(abs(diff_x) > abs(diff_y)) {
    if(diff_x > 0) {
      cout << 270 << endl;
    } else {
      cout << 90 << endl;
    }
  } else {
    if(diff_y > 0) {
      cout << 0 << endl;
    } else {
      cout << 180 << endl;
    }
  }
}