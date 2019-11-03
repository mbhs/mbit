import java.io.*;
import java.util.*;

public class LostChild {

	static double EPS = 1e-9;
	
	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), m = sc.nextInt();
		double a = sc.nextInt(), b = sc.nextInt();
		Point[] v1 = new Point[n], v2 = new Point[m];
		ArrayList<Point> w1 = new ArrayList<Point>(), w2 = new ArrayList<Point>();
		for(int i=0; i<n; i++){
	        int x = sc.nextInt(), y = sc.nextInt();
	        v1[i] = new Point(x,y);
	    }
	    for(int i=0; i<m; i++){
	        int x = sc.nextInt(), y = sc.nextInt();
	        v2[i] = new Point(x,y);
	    }

	    //Splicing
	    int i=1, j=1;
	    Point curr=v1[0], durr=v2[0];
	    w1.add(curr);
	    w2.add(durr);
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
	            double time = curr.to(v1[i]).mag()/a;
	            curr = v1[i];
	            i++;
	            durr = durr.add(durr.to(v2[j]).unit().times(time*b));
	            w1.add(curr);
	            w2.add(durr);
	        }else{
	            double time = durr.to(v2[j]).mag()/b;
	            durr = v2[j];
	            j++;
	            curr = curr.add(curr.to(v1[i]).unit().times(time*a));
	            w1.add(curr);
	            w2.add(durr);
	        }
	    }
	    if(i<n){
	        while(i<n){
	            w1.add(v1[i]);
	            w2.add(v2[m-1]);
	            i++;
	        }
	    }
	    if(j<m){
	        while(j<m){
	            w2.add(v2[j]);
	            w1.add(v1[n-1]);
	            j++;
	        }
	    }
	    double minimum = v1[0].to(v2[0]).mag();
	    for(int cnt = 0; cnt<w1.size()-1; cnt++){
	        minimum = custom_min(minimum, minDistance(w1.get(cnt),w1.get(cnt+1),w2.get(cnt),w2.get(cnt+1)));
	    }
	    System.out.println((long) (minimum + 0.5));
	    
	    sc.close();

	}
	
	static double minDistance(Point a, Point b, Point c, Point d){
	    Point v, w, s, t;
	    v = a.to(b);
	    w = c.to(d);
	    s = a.to(c);
	    t = v.to(w);
	    Point perp = new Point(t.y,-t.x);
	    if(perp.mag() < EPS){
	        return s.mag();
	    }
	    double perpDis = perp.proj(s);
	    double len = s.dist(s.add(t));
	    Point inter = perp.times(perpDis/perp.mag());
	    //is inter between endpoints?
	    if(Math.abs(len + s.dist(inter)-s.add(t).dist(inter))<EPS || Math.abs(len + s.add(t).dist(inter)-s.dist(inter))<EPS){
	        return custom_min(s.mag(),s.add(t).mag());
	    }else{
	        return Math.abs(perpDis);
	    }
	}
	
	static double custom_min(double a, double b) {
	    return a < b ? a : b;
	}
	
	static class Point {
		double x, y;
		
		Point() {
			x = y = 0;
		}
		
		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		double dist(Point p){
	        return Math.sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	    }
	    double mag(){
	        return dist(new Point());
	    }
	    Point to(Point p){
	        return new Point(p.x-x, p.y-y);
	    }
	    Point add(Point p){
	        return new Point(p.x+x, p.y+y);
	    }
	    double dot(Point p){
	        return x*p.x + y*p.y;
	    }
	    double proj(Point p){
	        return dot(p)/mag();
	    }
	    Point times(double k){
	        return new Point(x*k,y*k);
	    }
	    Point unit(){
	        return times(1/mag());
	    }
	}

}
