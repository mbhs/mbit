#include <bits/stdc++.h>

using namespace std;

const int L = 20;

using ld = long double;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<string> moves;
    
    vector<int> id(4);

    auto fill = [&](int x, int s) {
        s = id[s];
        string res = "F ";
        res += to_string(x);
        res += " ";
        res += (char)('a' + s - 1);
        moves.push_back(res);
    };

    auto empty = [&](int x) {
        moves.push_back("E " + to_string(x));
    };

    auto pour = [&](int x, int y) {
        moves.push_back("P " + to_string(x) + " " + to_string(y));
    };

    auto finish = [&](int x) { 
        moves.push_back("! " + to_string(x));
        cout << (int)moves.size() << '\n';
        for (auto& x : moves) {
            cout << x << '\n';
        }
        exit(0);
    };

    long double a, b, c; cin >> a >> b >> c;
    long double s = a + b + c;
    
    iota(id.begin(), id.end(), 0);
    if (a >= max(b, c)) {
 
    } else if (b >= max(a, c)) {
        swap(id[2], id[1]);   
        swap(a, b);
    } else {
        swap(id[3], id[1]);
        swap(a, c);
    }

    a /= s;
    b /= s;
    c /= s;

    a *= 2;
    b *= 2;
    c *= 2;

    auto make = [&](int i1, int i2, ld x) {
        fill(1, i2);
        pour(1, 2);
        ld v = 0;
        auto binary = [&](ld x) -> vector<int> {
            vector<int> res;
            x *= 2;
            for (int i = 0; i < L; ++i) {
                if (x >= 1) {
                    res.push_back(1);
                    x -= 1;
                } else {
                    res.push_back(0);
                }
                x *= 2;
            }
            return res;
        };

        auto digit = [&](int d) {
            fill(1, (d ? i1 : i2));
            pour(1, 2);
            pour(2, 1);
            empty(2);
            pour(1, 2);
        };

        vector<int> bin = binary(x);
        reverse(bin.begin(), bin.end());
        for (auto& d : bin) 
            digit(d);

        pour(2, 3);
    }; 

    make(2, 1, b);
    make(3, 1, c);

    finish(3);

    return 0;
}