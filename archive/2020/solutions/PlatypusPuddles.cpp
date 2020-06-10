#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > node;

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}

int main(){
    fast_io();

    int n;
    cin >> n;
    vector<vector<int> > grid(n, vector<int>(n));
    vector<vector<bool> > visited(n, vector<bool>(n));
    priority_queue<node, vector<node>, greater<node> > queue;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> grid[i][j];

        if(i==0 || i==n-1 || j==0 || j==n-1){
          queue.push(make_pair(grid[i][j], make_pair(i, j)));
        }
      }
    }

    long long ans = 0;
    while(queue.size() > 0){
      node x = queue.top();
      queue.pop();
      int i, j, val;
      i = x.second.first;
      j = x.second.second;
      val = x.first;

      if(visited[i][j]) continue;
      visited[i][j] = true;
      ans += val-grid[i][j];
      if(i>0) queue.push(make_pair(max(val, grid[i-1][j]), make_pair(i-1, j)));
      if(i<n-1) queue.push(make_pair(max(val, grid[i+1][j]), make_pair(i+1, j)));
      if(j>0) queue.push(make_pair(max(val, grid[i][j-1]), make_pair(i, j-1)));
      if(j<n-1) queue.push(make_pair(max(val, grid[i][j+1]), make_pair(i, j+1)));
    }

    cout << ans << endl;

}
