#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Evan Wang || MBHS 2021

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, a, b, c, d;
    cin >> n >> m >> x >> y >> a >> b >> c >> d;

    int k = -1000;
    int ans = INT32_MAX;
    for(; k <= 1000; k++){
        int needAppleCount = a + k*c - n;
        int needBlazeCount = b - k*d - m;
        int subAns = 0;
        if(needAppleCount > 0){
            subAns += needAppleCount * x;
        }
        if(needBlazeCount > 0){
            subAns += needBlazeCount * y;
        }
        ans = min(ans, subAns);
    }
    cout << ans << '\n';
}
