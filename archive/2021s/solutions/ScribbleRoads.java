import java.util.*;
import java.io.*;

public class ScribbleRoads {

	static HashMap<Long, Boolean> ans;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		OutputWriter out = new OutputWriter(System.out);
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt(), m = sc.nextInt();
			ArrayList<Integer>[] adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			UnionFind dsu = new UnionFind(n);
			for (int i = 0; i < m; i++) {
				int u = sc.nextInt(), v = sc.nextInt();
				dsu.join(u - 1, v - 1);
			}
			int x = 0;
			int y = 0;
			int d = 0;
			for (int i = 0; i < n; i++) {
				if (i == dsu.find(i)) {
					int sz = dsu.size[i];
					if (sz % 2 == 1) {
						x += 1;
					} else {
						y += 1;
					}
					d += sz * (sz - 1) / 2;
				}
			}
			d -= m;
			d %= 2;
			ans = new HashMap<>();
			boolean win = false;
			if (x < 10 && y < 10) {
				win = solve(x, y, d);
			} else {
				if (d == 0) {
					if (y < 2) {
						win = (x % 4 == 0 || x % 4 == 3);
					} else if (y == 2) {
						win = (x % 4 == 0 || x % 4 == 2 || x % 4 == 3);
					} else {
						win = (x % 4 == 2 || x % 4 == 3);
					}
				} else {
					if (y < 2) {
						win = (x % 4 == 1 || x % 4 == 2);
					} else if (y == 2) {
						win = (x % 4 == 0 || x % 4 == 1 || x % 4 == 2);
					} else {
						win = (x % 4 == 0 || x % 4 == 1);
					}
				}
			}
			if (win)
				out.print("WIN\n");
			else
				out.print("LOSE\n");
		}
		out.close();
	}

	static boolean solve(int x, int y, int d) {
		long temp = encode(x, y, d);
		if (ans.containsKey(temp))
			return ans.get(temp);
		if (x + y == 1)
			ans.put(temp, false);
		else if (x + y == 2)
			ans.put(temp, true);
		else {
			boolean bad = true;
			if (x >= 2)
				bad &= solve(x - 2, y + 1, d);
			if (y >= 1)
				bad &= solve(x, y - 1, 1 - d);
			if (d == 1)
				bad &= solve(x, y, 0);
			ans.put(temp, !bad);
		}
		return ans.get(temp);
	}

	static long encode(int x, int y, int d) {
		return 18408749 * x + 17841869 * y + 16402271 * d;
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

class Scanner {
	public BufferedReader reader;
	public StringTokenizer st;

	public Scanner(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		st = null;
	}

	public String next() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				String line = reader.readLine();
				if (line == null)
					return null;
				st = new StringTokenizer(line);
			} catch (Exception e) {
				throw (new RuntimeException());
			}
		}
		return st.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}

class OutputWriter {
	BufferedWriter writer;

	public OutputWriter(OutputStream stream) {
		writer = new BufferedWriter(new OutputStreamWriter(stream));
	}

	public void print(int i) throws IOException {
		writer.write(i);
	}

	public void print(String s) throws IOException {
		writer.write(s);
	}

	public void print(char[] c) throws IOException {
		writer.write(c);
	}

	public void close() throws IOException {
		writer.close();
	}

}