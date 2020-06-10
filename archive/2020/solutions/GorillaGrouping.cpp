#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k;
map<int, int> exist;
bool used[MAXN];
int fib[MAXN];
int recurse(int x, int len){
    used[exist[x]] = true;
    if(exist.find(x+k) == exist.end()) return len;
    else return recurse(x+k, len+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<MAXN; i++){
        if(i == 0) fib[0] = 1;
        else if(i == 1) fib[i] = 2;
        else{
            fib[i] = fib[i-1] + fib[i-2];
            if(fib[i] >= MOD) fib[i] -= MOD;
        }
    }
    cin >> n >> k;
    vector<int> id;
    for(int i = 0; i<n; i++){
        int x; cin >> x; id.emplace_back(x);
    }
    sort(id.begin(), id.end());
    for(int i = 0; i<n; i++) exist[id[i]] = i;
    vector<int> chains;
    for(int i = 0; i<n; i++){
        if(used[i]) continue;
        else chains.emplace_back(recurse(id[i], 1));
    }
    long long ans = 1;
    for(int x: chains){
        ans *= fib[x];
        ans %= MOD;
    }
    cout << ans - 1 << endl;
    return 0;
}

