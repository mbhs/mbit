#include<bits/stdc++.h>
using namespace std;
const int MAX = 8e3 + 5;
const double INF = 1e18;
double a[MAX];
double dp[MAX];
double pre[MAX];
double preSquare[MAX];

double get(int i, int j){
    if(i>j) swap(i, j);
    double res = preSquare[j] - (i == 0 ? 0:preSquare[i-1]);
    double sum = pre[j] - (i == 0? 0: pre[i-1]);
    return res - 2*sum*sum/(j-i+1) + sum*sum/(j-i+1);
}
int main(){
    int n, k;
    cin >> n >> k;
    if(k == 0){
        cout << 0 << endl;
        return 0;
    } 
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++){
        if(i == 0) preSquare[i] = a[i]*a[i], pre[i] = a[i];
        else preSquare[i] = preSquare[i-1] + a[i]*a[i], pre[i] = pre[i-1] + a[i];
    }
    for(int i = 0; i<MAX; i++){
        dp[i] = INF;
    }
    for(int i = 0; i<n; i++){
        if(i>= k-1) dp[i] = get(0, i);
        for(int j = 0; j<=i-k; j++){
            dp[i] = min(dp[i], dp[j] + get(j+1, i));
        }
    }
    cout << (long long)dp[n-1] << endl;
    return 0;
}
