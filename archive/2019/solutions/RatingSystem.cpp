#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, o;
    char result;
    cin >> c >> o >> result;

    if (result == 'w')
        cout << c + o / 10 << endl;
    else
        cout << (c / 10) * 9 << endl;

    return 0;
}