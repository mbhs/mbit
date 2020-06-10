#include <bits/stdc++.h>
using namespace std;
const int MAX = 62;
bool in[MAX];
char get_char(int x){
    assert(x < 62);
    if(x<10){
        return (char) (x + '0');
    }
    x-=10;
    if(x<26){
        return (char) ('a'+x);
    }
    x -= 26;
    return (char) ('A' + x);
    
}
bool answer(vector<int> v){
    for(int x: v) cout << get_char(x);
    cout << endl;
    string response; cin >> response;
    if(response[0] == 'C') return true;
    return false;
}
bool ask(int x){
    cout << get_char(x) << endl;
    string response; cin >> response;
    if (response[0] == 'C') exit(0);
    if(response[0] == 'Y') return true;
    return false;
}
bool ask(pair<int, int> x){
    cout << get_char(x.first) << get_char(x.second) << endl;
    string response; cin >> response;
    if (response[0] == 'C') exit(0);
    if(response[0] == 'Y') return true;
    return false;
}
bool compare(int i, int j){ return ask(make_pair(i, j)); }
int main(){
    for(int i = 0; i<MAX; i++) in[i] = ask(i);
    vector<int> v;
    for(int i = 0; i<MAX; i++) if(in[i]) v.emplace_back(i);
    sort(v.begin(), v.end(), compare);
    assert(answer(v));
    
    return 0;
}
