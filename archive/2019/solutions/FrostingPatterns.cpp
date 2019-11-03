#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int p=1; p<=n/2; p++){
        bool works = true;
        for(int i=0; i<n; i++){
            if(v[i] != v[i%p]){
                works = false;
                break;
            }
        }
        if(works){
            for(int i=n; i<n+m; i++){
                cout << v[i%p];
            }
            cout << endl;
            break;
        }
    }
}