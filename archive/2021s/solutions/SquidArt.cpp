#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a:x)
#define all(x) begin(x), end(x)
#define sz(x) x.size()
#define f first
#define s second
#define nl '\n'
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m;
vector<string> A;
vi adj[100000];
int par[100000];
map<pii, bool> mp;
int dx[]={0, 0, 1, 1, -1, -1};
int dy[]={1, -1, 0, 1, 0, 1}; //even rows
int mx;
bool vis[100000];
int a, b;

void dfs(int x, int d){
    vis[x]=1;
    if(d>mx && A[x/m][x%m]=='0'){ //one endpoint white
        a=x;
        mx=d;
    }
    trav(k, adj[x]){
        if(!vis[k]) dfs(k, d+1);
    }
}

void dfs1(int x, int d){
    vis[x]=1;
    if(d>mx){
        b=x;
        mx=d;
    }
    trav(k, adj[x]){
        if(!vis[k]) dfs1(k, d+1);
    }
}

int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void join(int x, int y){
    int a=find(x);
    int b=find(y);
    par[a]=b;
}

void connect(int x, int y){
    int a=find(x);
    int b=find(y);
    if(!mp[{a, b}]){
        mp[{a, b}]=mp[{b, a}]=1;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}

int id(int x, int y){ return m*x+y; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> m;
    A.resize(n);

    rep(i, 0, n-1){
        rep(j, 0, m-1){
            par[id(i, j)]=id(i, j);
        }
        cin >> A[i];
    }

    for(int i=0; i<n; i+=2) {
        rep(j, 0, m-1){
            rep(k, 0, 5){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && A[i][j]==A[nx][ny]){
                    join(id(i, j), id(nx, ny));
                }
            }
        }
    }

    rep(i, 0, n-1){
        rep(j, 0, m-1){
            rep(k, 0, 1){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && A[i][j]==A[nx][ny]){
                    join(id(i, j), id(nx, ny));
                }
            }
        }
    }

    for(int i=0; i<n; i+=2) {
        rep(j, 0, m-1){
            rep(k, 0, 5){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && A[i][j]!=A[nx][ny]){
                    connect(id(i, j), id(nx, ny));
                }
            }
        }
    }

    rep(i, 0, n-1){
        rep(j, 0, m-1){
            rep(k, 0, 1){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && A[i][j]!=A[nx][ny]){
                    connect(id(i, j), id(nx, ny));
                }
            }
        }
    }

    dfs(find(0), 0);
    rep(i, 0, n*m-1) vis[i]=0;
    mx=0;
    dfs1(a, 0);
    cout << mx/2+1;
}