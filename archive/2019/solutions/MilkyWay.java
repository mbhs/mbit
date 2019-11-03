import java.io.*;
import java.util.*;

public class MilkyWay {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), m = sc.nextInt(), c = sc.nextInt();
		int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
		int[] p = new int[n];
		for (int i=0; i<n; i++)
			p[i] = sc.nextInt();
		
		List<Edge>[] adj = new List[n];
		for (int i=0; i<n; i++)
			adj[i] = new LinkedList<Edge>();
		for (int i=0; i<m; i++) {
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1, z = sc.nextInt();
			adj[x].add(new Edge(y, z));
			adj[y].add(new Edge(x, z));
		}
		
		boolean[][] visited = new boolean[n][c+1];
		LinkedList<Q> q = new LinkedList<Q>();
		q.add(new Q(a, 0, 0));
		while (!q.isEmpty()) {
			Q cur = q.pop();
			
			if (cur.fuel > c)
				cur.fuel = c;
			if (cur.fuel < 0 || visited[cur.node][cur.fuel])
				continue;
			if (cur.node == b) {
				System.out.println(cur.dist);
				break;
			}
			
			visited[cur.node][cur.fuel] = true;
			q.add(new Q(cur.node, cur.fuel + p[cur.node], cur.dist + 1));
			for (Edge e : adj[cur.node])
				q.add(new Q(e.v, cur.fuel - e.w, cur.dist + 1));
		}
		
		sc.close();

	}
	
	static class Edge {
		int v, w;
		
		public Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}
	
	static class Q {
		int node, fuel, dist;
		
		public Q(int node, int fuel, int dist) {
			this.node = node;
			this.fuel = fuel;
			this.dist = dist;
		}
	}

}
