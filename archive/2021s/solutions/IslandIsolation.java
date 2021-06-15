import java.util.*;
import java.io.*;

public class IslandIsolation {

	static ArrayList<Integer>[] adj;
	static ArrayList<int[]> out;
	static boolean[] vis;

	public static void main(String[] args) throws IOException {
		Scanner2 sc = new Scanner2(System.in);
		int n = sc.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		out = new ArrayList<>();
		vis = new boolean[n];
		vis[0] = true;
		dfs1(-1, 0);
		vis = new boolean[n];
		vis[0] = true;
		dfs2(0);
		OutputWriter out2 = new OutputWriter(System.out);
		for (int i = 0; i < 2 * (n - 1); i++) {
			out2.print(out.get(i)[0] + " " + out.get(i)[1]);
			out2.print("\n");
		}
		out2.close();
	}

	public static void dfs1(int par, int curr) {
		for (int next : adj[curr]) {
			if (!vis[next]) {
				vis[next] = true;
				dfs1(curr, next);
			}
		}

		if (par != -1) {
			out.add(new int[] { par + 1, curr + 1 });
		}
	}

	public static void dfs2(int curr) {
		for (int next : adj[curr]) {
			if (!vis[next]) {
				vis[next] = true;
				out.add(new int[] { next + 1, curr + 1 });
				dfs2(next);
			}
		}
	}

}

class Scanner2 {
	public BufferedReader reader;
	public StringTokenizer st;

	public Scanner2(InputStream stream) {
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