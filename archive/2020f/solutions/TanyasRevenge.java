import java.util.*;
import java.io.*;

// By Ayush Varshney
public class TanyasRevenge {
	static int[][] up, down;
	static ArrayList<Integer>[] adj;
	static boolean[] red;
	static int n;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		red = new boolean[n];
		String s = sc.next();
		for (int i = 0; i < n; i++) {
			red[i] = s.charAt(i) == '1';
		}
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		up = new int[n][n + 1];
		down = new int[n][n + 1];
		System.out.println(dfs(0, -1));
		sc.close();
	}

	static int dfs(int u, int par) {
		for (int child : adj[u]) {
			if (child != par) {
				dfs(child, u);
			}
		}
		if (red[u]) {
			for (int k = 0; k < n; k++) {
				up[u][k] = k;
				down[u][k] = k;
				for (int child : adj[u]) {
					if (child != par) {
						up[u][k] += Math.max(up[child][k + 1], down[child][1]);
						down[u][k] += Math.max(up[child][1], down[child][k + 1]);
					}
				}
			}
		} else {
			for (int k = 0; k < n; k++) {
				up[u][k] = k;
				down[u][k] = 0;
				for (int child : adj[u]) {
					if (child != par) {
						up[u][k] += Math.max(up[child][k], down[child][1]);
						down[u][k] += Math.max(up[child][0], down[child][k + 1]);
					}
				}
			}
		}
		return up[0][0];
	}

}