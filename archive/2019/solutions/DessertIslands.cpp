#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > swamp(n,vector<bool>(m));
    vector<vector<int> > grounds(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin >> x;
            swamp[i][j] =  x=='S'? true : false;
        }
    }
    int islands = 0;
    int lakes = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grounds[i][j] != 0){
                continue;
            }
            if(swamp[i][j]){
                islands++;
                vector<pair<int,int> > next;
                next.push_back(make_pair(i,j));
                while(!next.empty()){
                    pair<int,int> c = next.back();
                    int x = c.first;
                    int y = c.second;
                    next.pop_back();
                    if(x>=0 && x<n && y>=0 && y<m && swamp[x][y] && grounds[x][y]==0){
                        grounds[x][y] = islands;
                        next.push_back(make_pair(x-1,y));
                        next.push_back(make_pair(x+1,y));
                        next.push_back(make_pair(x,y-1));
                        next.push_back(make_pair(x,y+1));
                    }
                }
            }else{
                lakes++;
                vector<pair<int,int> > next;
                next.push_back(make_pair(i,j));
                while(!next.empty()){
                    pair<int,int> c = next.back();
                    int x = c.first;
                    int y = c.second;
                    next.pop_back();
                    if(x>=0 && x<n && y>=0 && y<m && swamp[x][y]==false && grounds[x][y] == 0){
                        grounds[x][y] = -lakes;
                        next.push_back(make_pair(x-1,y));
                        next.push_back(make_pair(x+1,y));
                        next.push_back(make_pair(x,y-1));
                        next.push_back(make_pair(x,y+1));
                    }
                }
            }
        }
    }
    cout << islands-1 << " " << lakes << endl;

}