#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct Point{
    long double x;
    long double y;
    Point():x(0),y(0){}
    Point(long double x, long double y): x(x),y(y){}
    long double dist(Point p){
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }
    long double mag(){
        return dist(Point());
    }
    Point to(Point p){
        return Point(p.x-x, p.y-y);
    }
    Point add(Point p){
        return Point(p.x+x, p.y+y);
    }
    long double dot(Point p){
        return x*p.x + y*p.y;
    }
    long double proj(Point p){
        return dot(p)/mag();
    }
    Point times(long double k){
        return Point(x*k,y*k);
    }
    Point unit(){
        return times(1/mag());
    }
    string str(){
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

long double minDistance(Point a, Point b, Point c, Point d){
    Point v, w, s, t;
    v = a.to(b);
    w = c.to(d);
    s = a.to(c);
    t = v.to(w);
    Point perp(t.y,-t.x);
    if(perp.mag() < EPS){
        return s.mag();
    }
    long double perpDis = perp.proj(s);
    long double len = s.dist(s.add(t));
    Point inter = perp.times(perpDis/perp.mag());
    //is inter between endpoints?
    if(abs(len + s.dist(inter)-s.add(t).dist(inter))<EPS || abs(len + s.add(t).dist(inter)-s.dist(inter))<EPS){
        return min(s.mag(),s.add(t).mag());
    }else{
        return abs(perpDis);
    }
}
int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    //Point a(1,0), b(1,1), c(2,1),d(1,0);
    //cout << minDistance(a,b,c,d);
    vector<Point> v1(n), v2(m), w1, w2;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v1[i] = Point(x,y);
    }
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v2[i] = Point(x,y);
    }

    //Splicing
    int i=1, j=1;
    Point curr=v1[0], durr=v2[0];
    w1.push_back(curr);
    w2.push_back(durr);
    while(i<n && j<m){
        if(curr.to(v1[i]).mag() < EPS){
            curr = v1[i];
            i++;
            continue;
        }
        if(durr.to(v2[j]).mag() < EPS){
            durr = v2[j];
            j++;
            continue;
        }
        if(curr.to(v1[i]).mag()/a < durr.to(v2[j]).mag()/b){
            long double time = curr.to(v1[i]).mag()/a;
            curr = v1[i];
            i++;
            durr = durr.add(durr.to(v2[j]).unit().times(time*b));
            w1.push_back(curr);
            w2.push_back(durr);
        }else{
            long double time = durr.to(v2[j]).mag()/b;
            durr = v2[j];
            j++;
            curr = curr.add(curr.to(v1[i]).unit().times(time*a));
            w1.push_back(curr);
            w2.push_back(durr);
        }
    }
    if(i<n){
        while(i<n){
            w1.push_back(v1[i]);
            w2.push_back(v2[m-1]);
            i++;
        }
    }
    if(j<m){
        while(j<m){
            w2.push_back(v2[j]);
            w1.push_back(v1[n-1]);
            j++;
        }
    }
    long double minimum = v1[0].to(v2[0]).mag();
    for(int cnt = 0; cnt<w1.size()-1; cnt++){
        //cout << w1[cnt+1].str() << " " << w2[cnt+1].str() << endl;
        minimum = min(minimum, minDistance(w1[cnt],w1[cnt+1],w2[cnt],w2[cnt+1]));
    }
    /*
    int intmin = (int) minimum;
    minimum -= intmin;
    minimum *= 1000;*/
    cout << (long long) (minimum + 0.5) << endl;

}
