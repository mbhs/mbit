#include<bits/stdc++.h>
using namespace std;
vector<pair<double, double>> p;
const double PI = 4*atan(1);
double get(pair<double, double> o, pair<double, double> a, pair<double, double> b){
    double x1 = a.first - o.first;
    double y1 = a.second - o.second;
    double x2 = b.first - o.first;
    double y2 = b.second - o.second;
    return x1*y2 - y1*x2;
}
const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;

long long po[MAX];


bool check(int x, int y) {
    int counter = 0;
    pair<double, double> p1 = p[0], p2;
    for (int i=1; i<=p.size(); i++) {
        p2 = p[i % p.size()];
        if ((p2.first - p1.first) * (y - p1.second) - (p2.second - p1.second) * (x - p1.first) == 0)    // lies on polygon border
            return false;
        if (y > min(p1.second, p2.second) && y <= max(p1.second, p2.second) && x <= max(p1.first, p2.first) && p1.second != p2.second && (p1.first == p2.first || x <= (y - p1.second) * (p2.first - p1.first) / (p2.second - p1.second) + p1.first))
            counter++;
        p1 = p2;
    }

    return counter % 2 == 1;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        p.emplace_back(make_pair(x, y));
    }
    for(int i = 0; i<MAX; i++){
        if(i == 0) po[i] = 1;
        else po[i] = (po[i-1]*2)%MOD;
    }
    while(q--){
        long long N = n;
        long long tot = po[n] - N - 1 - N*(N-1)/2;
        double x, y;
        cin >> x >> y;
        if(check(x, y) == 0){
            cout << 0 << endl;
            continue;
        }
        pair<double, double> o = make_pair(x, y);
        int j = 1;
        for(int i = 0; i<n; i++){
            while(get(o, p[i], p[j])>0){
                j++;
                j%=n;
            }

            if(i == j) continue;
            int between;
            if(i<= j){
                between = j - i + 1;
            }
            else{
                between = n-1 - i + 1 +j+1;
            }
            int choose = n - between + 1;
            tot -= (po[choose] - 1 - choose);
            tot %= MOD;
            tot += MOD;
            tot %= MOD;
        }
        cout << tot << endl;
    }
    return 0;
}
