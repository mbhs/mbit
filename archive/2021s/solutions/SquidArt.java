import java.util.*;
import java.io.*;

public class SquidArt {

	static int n, m;
	static ArrayList<Integer>[] adj;
	static UnionFind d;
	static ArrayList<Integer> path;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		char[] a = new char[n * m];
		d = new UnionFind(n * m);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			char[] temp = sc.next().toCharArray();
			for (char c : temp) {
				a[cnt] = c;
				cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j < m - 1)
					if (a[i * m + j] == a[i * m + j + 1])
						d.join(i * m + j, i * m + j + 1);
				if (i < n - 1) {
					if (a[i * m + j] == a[(i + 1) * m + j])
						d.join(i * m + j, (i + 1) * m + j);
					if (i % 2 == 0) {
						if (j < m - 1 && a[i * m + j] == a[(i + 1) * m + j + 1])
							d.join(i * m + j, (i + 1) * m + j + 1);
					} else {
						if (j > 0 && a[i * m + j] == a[(i + 1) * m + j - 1])
							d.join(i * m + j, (i + 1) * m + j - 1);
					}
				}
			}
		}

		int x = d.count;
		int[] root = new int[n * m];
		for (int i = 0; i < n * m; i++) {
			root[i] = d.find(i);
		}
		adj = new ArrayList[n * m];
		for (int i = 0; i < n * m; i++) {
			adj[i] = new ArrayList<>();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j < m - 1)
					if (a[i * m + j] != a[i * m + j + 1] && !d.connected(i * m + j, i * m + j + 1)) {
						adj[root[i * m + j]].add(root[i * m + j + 1]);
						adj[root[i * m + j + 1]].add(root[i * m + j]);
						d.join(i * m + j, i * m + j + 1);
					}
				if (i < n - 1) {
					if (a[i * m + j] != a[(i + 1) * m + j] && !d.connected(i * m + j, (i + 1) * m + j)) {
						adj[root[i * m + j]].add(root[(i + 1) * m + j]);
						adj[root[(i + 1) * m + j]].add(root[i * m + j]);
						d.join(i * m + j, (i + 1) * m + j);
					}
					if (i % 2 == 0) {
						if (j < m - 1 && a[i * m + j] != a[(i + 1) * m + j + 1]
								&& !d.connected(i * m + j, (i + 1) * m + j + 1)) {
							adj[root[i * m + j]].add(root[(i + 1) * m + j + 1]);
							adj[root[(i + 1) * m + j + 1]].add(root[i * m + j]);
							d.join(i * m + j, (i + 1) * m + j + 1);
						}
					} else {
						if (j > 0 && a[i * m + j] != a[(i + 1) * m + j - 1]
								&& !d.connected(i * m + j, (i + 1) * m + j - 1)) {
							adj[root[i * m + j]].add(root[(i + 1) * m + j - 1]);
							adj[root[(i + 1) * m + j - 1]].add(root[i * m + j]);
							d.join(i * m + j, (i + 1) * m + j - 1);
						}
					}
				}
			}
		}

		int far = dfs(root[0], -1)[1];
		int dist = dfs(far, -1)[0];

		if (dist % 2 == 1) {
			System.out.println((dist + 1) / 2);
		} else {
			if (a[far] == '1') {
				System.out.println(dist / 2);
			} else {
				System.out.println(dist / 2 + 1);
			}
		}
		sc.close();
	}

	static int[] dfs(int u, int p) {
		int[] best = new int[] { 0, u };
		for (int v : adj[u])
			if (v != p) {
				int[] x = dfs(v, u);
				if (x[0] + 1 > best[0]) {
					best = new int[] { x[0] + 1, x[1] };
				} else if (x[0] + 1 == best[0] && x[1] > best[1]) {
					best = new int[] { x[0] + 1, x[1] };
				}
			}
		return best;
	}
}

class UnionFind {
	int count;
	int[] parent;
	int[] size;

	public UnionFind(int m) {
		this.count = m;
		this.parent = new int[m];
		this.size = new int[m];
		for (int i = 0; i < m; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	public int find(int A) {
		while (this.parent[A] != A) {
			int prev = A;
			A = this.parent[A];
			this.parent[prev] = this.parent[A];
		}
		return A;
	}

	public boolean connected(int p, int q) {
		return find(p) == find(q);
	}

	public void join(int p, int q) {
		int root1 = find(p);
		int root2 = find(q);
		if (root1 == root2)
			return;
		if (this.size[root1] < this.size[root2]) {
			this.parent[root1] = root2;
			this.size[root2] += this.size[root1];
		} else {
			this.parent[root2] = root1;
			this.size[root1] += this.size[root2];
		}
		this.count--;
	}
}