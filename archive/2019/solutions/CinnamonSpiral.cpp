#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    long long ox = x;
    long long oy = y;
    if(x == 0 && y == 0) cout << 0 << endl;
    long long a = max(abs(x), abs(y));
    long long add = 4*a*a - 3*a;
    if(abs(x)>abs(y)){
        x = abs(x);
        if(ox>0) cout << add + y << endl;
        else cout << add - y + 4*x<< endl;
    }
    else{
        y = abs(y);
        if(oy>0) cout << add + y*2 - x << endl;
        else cout << add + y*6 +x << endl;
    }
    return 0;
}