#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    vector<int> cnt(c,0);
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i]--;
    }
    int p1 = 0;
    int p2 = -1;
    int c0 = c;
    while(c0>0){
        p2++;
        cnt[v[p2]]++;
        if(cnt[v[p2]] == 1){
            c0--;
        }
    }
    pair<int, int> best = make_pair(p1,p2);
    while(p1<n-1){
        cnt[v[p1]]--;
        if(cnt[v[p1]]==0){
            c0++;
        }
        p1++;
        while(c0>0 && p2<n-1){
            p2++;
            cnt[v[p2]]++;
            if(cnt[v[p2]] == 1){
                c0--;
            }
        }
        if(c0>0){
            break;
        }
        best = best.second-best.first < p2-p1 ? best:make_pair(p1,p2);
    }

    cout << best.first << " " << n-(best.second+1) << endl;
}