import java.io.*;
import java.util.*;

@SuppressWarnings("unchecked")
public class SecretBase {
	
	static int n, m, k;
	static int[] depth = new int[100000], cost = new int[100000];
	static int[][] par = new int[100000][20];
	
	static ArrayList<Integer>[] adj = new ArrayList[100000];
	static ArrayList<Route>[] routes = new ArrayList[100000];

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		for (int i=0; i<n; i++) {
			adj[i] = new ArrayList<Integer>();
			routes[i] = new ArrayList<Route>();
		}
		for (int i=0; i<n-1; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			adj[u].add(v);
			adj[v].add(u);
		}
		for (int i=0; i<m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1, w = sc.nextInt();
			routes[u].add(new Route(v, w));
			routes[v].add(new Route(u, w));
		}
		
		process();
		long ret = Long.MAX_VALUE;
	    for(int i = 0; i<n; i++){
	    	HashMap<Integer, PriorityQueue<Long>> sub = new HashMap<>();
	        for(int j = 0; j<routes[i].size(); j++){
	        	int key = get_ancestor(i, routes[i].get(j).v);
	        	if (!sub.containsKey(key))
	        		sub.put(key, new PriorityQueue<Long>());
	        	sub.get(key).add((long) routes[i].get(j).w);
	        }
	        for(PriorityQueue<Long> x: sub.values()){
	            if(x.size() >= k){
	                long val = 0;
	                int cnt = 0;
	                while (!x.isEmpty()){
	                    val += x.poll();
	                    cnt++;
	                    if(cnt == k) break;
	                }
	                ret = Math.min(ret, val);
	            }
	        }
	    }
	    
	    System.out.println(ret == Long.MAX_VALUE ? -1 : ret);
	    
	    sc.close();

	}
	
	static class Route {
		int v, w;
		
		Route(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}
	
	static void dfs(int cur, int prev) {
	    par[cur][0] = prev;
	    for (int nxt : adj[cur]) {
	        if (nxt == prev)
	            continue;
	        depth[nxt] = depth[cur] + 1;
	        dfs(nxt, cur);
	    }
	}

	static void process() {
	    depth[0] = 0;
	    dfs(0, 0);
	    for (int lvl = 0; lvl < 19; lvl ++) for (int cur = 0; cur< n; cur++) {
	        int mid = par[cur][lvl];
	        par[cur][lvl + 1] = par[mid][lvl];
	    }
	}

	static int above(int u, int k) {
	    for (int it = 19; it >= 0; it--)
	        if (k >= (1 << it)){
	            u = par[u][it];
	            k -= (1<<it);
	        }
	    return u;
	}

	static int get_ancestor(int top, int bot){
	    if(depth[top]>= depth[bot]){
	        return par[top][0];
	    }
	    int anc = above(bot, depth[bot] - depth[top] - 1);
	    if(par[anc][0] == top){
	        return anc;
	    }
	    return par[top][0];
	}

}
