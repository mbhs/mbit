import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Rams {
	static int n, m, k;
	static int[] dr = new int[] { 0, 0, -1, 1 };
	static int[] dc = new int[] { 1, -1, 0, 0 };

	public static void main(String[] args) throws IOException {
		Scanner2 sc = new Scanner2(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		k = sc.nextInt();
		int[][] grid = new int[n][m];
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == '#') {
					grid[i][j] = 1;
				} else {
					grid[i][j] = 0;
				}
			}
		}
		int[][] special = new int[k][2];
		for (int i = 0; i < k; i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			special[i] = new int[] { a - 1, b - 1 };
		}
		int[][][] dists = new int[k][n][m];
		for (int i = 0; i < k; i++) {
			ArrayDeque<int[][]> dq = new ArrayDeque<>();
			dq.addFirst(new int[][] { special[i], new int[] { grid[special[i][0]][special[i][1]] } });
			int[][] vis = new int[n][m];
			while (!dq.isEmpty()) {
				int[][] cur = dq.removeFirst();
				int[] loc = cur[0];
				int r = loc[0], c = loc[1];
				int dist = cur[1][0];
				if (vis[r][c] == 1)
					continue;
				vis[r][c] = 1;
				dists[i][r][c] = dist;
				for (int d = 0; d < 4; d++) {
					int nr = r + dr[d], nc = c + dc[d];
					if (valid(nr, nc)) {
						if (grid[nr][nc] == 1) {
							dq.addLast(new int[][] { new int[] { nr, nc }, new int[] { dist + 1 } });
						} else {
							dq.addFirst(new int[][] { new int[] { nr, nc }, new int[] { dist } });
						}
					}
				}
			}
		}
		int[][] edge_dist = new int[n][m];
		ArrayDeque<int[][]> dq = new ArrayDeque<>();
		for (int i = -1; i <= n; i++) {
			dq.addLast(new int[][] { new int[] { i, -1 }, new int[] { 0 } });
			dq.addLast(new int[][] { new int[] { i, m }, new int[] { 0 } });
		}
		for (int i = -1; i <= m; i++) {
			dq.addLast(new int[][] { new int[] { -1, i }, new int[] { 0 } });
			dq.addLast(new int[][] { new int[] { n, i }, new int[] { 0 } });
		}
		int[][] vis = new int[n][m];
		while (!dq.isEmpty()) {
			int[][] cur = dq.removeFirst();
			int[] loc = cur[0];
			int r = loc[0], c = loc[1];
			int dist = cur[1][0];
			if (valid(r, c)) {
				if (vis[r][c] == 1)
					continue;
				vis[r][c] = 1;
				edge_dist[r][c] = dist;
			}
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (valid(nr, nc)) {
					if (grid[nr][nc] == 1) {
						dq.addLast(new int[][] { new int[] { nr, nc }, new int[] { dist + 1 } });
					} else {
						dq.addFirst(new int[][] { new int[] { nr, nc }, new int[] { dist } });
					}
				}
			}
		}
		int best = (int) 1e9;
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				best = Math.min(best,
						edge_dist[special[i][0]][special[i][1]] + edge_dist[special[j][0]][special[j][1]]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				Integer[] dist_vals = new Integer[k];
				for (int x = 0; x < k; x++) {
					dist_vals[x] = dists[x][i][j];
				}
				Arrays.sort(dist_vals);
				int cost = dist_vals[0] + dist_vals[1] + edge_dist[i][j];
				if (grid[i][j] == 1)
					cost -= 2;
				best = Math.min(best, cost);
			}
		}
		System.out.println(best);
	}

	public static boolean valid(long r, long c) {
		return r >= 0 && r < n && c >= 0 && c < m;
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