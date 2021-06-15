#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Evan Wang | MBHS 2021

int gcd(int a, int b){
    if(b == 0) return a;
    a %= b;
    return gcd(b, a);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int n;
    string s;
    // cin >> n >> s;
    cin >> s;
    int n = (int) s.size();
    if(n == 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> letFreqs(26, 0);
    for(int i = 0; i < n; i++){
        letFreqs[s[i]-'a']++;
    }
    int commonDiv = gcd(letFreqs[0], letFreqs[1]);
    for(int i = 2; i < 26; i++){
        commonDiv = gcd(commonDiv, letFreqs[i]);
    }
    if(commonDiv == 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0; i < 26; i++){
        letFreqs[i] /= commonDiv;
    }
    for(int i = 0; i < commonDiv; i++){
        for(int j = 0; j < 26; j++){
            for(int k = 0; k < letFreqs[j]; k++){
                cout << (char) ('a' + j);
            }
        }
    }
    cout << '\n';
}
