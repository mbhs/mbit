import java.util.*;
import java.io.*;

public class GridShuffling {

	static int n, k;
	static int[][] board;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		OutputWriter out = new OutputWriter(System.out);
		n = sc.nextInt();
		k = sc.nextInt();
		int[][] orig = new int[n][n];
		board = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				orig[i][j] = sc.nextInt();
		int[] m = new int[n * n + 1];
		int it = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (orig[i][j] > 0) {
					board[i][j] = it;
					m[it] = orig[i][j];
					it++;
				}

		if (k <= 4) {
			down();
			if (k > 1)
				right();
			if (k > 2)
				up();
			if (k > 3)
				left();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					out.print(m[board[i][j]] + " ");
				out.print("\n");
			}
		} else {
			down();
			right();
			up();
			left();
			k -= 4;
			int[][] before = new int[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					before[i][j] = board[i][j];
			down();
			right();
			up();
			left();
			int[] perm = new int[it];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (board[i][j] > 0)
						perm[before[i][j]] = board[i][j];
			int[] ans = new int[it];
			for (int i = 1; i < it; i++) {
				if (ans[i] > 0)
					continue;
				ArrayList<Integer> cycle = new ArrayList<Integer>();
				cycle.add(i);
				int curr = perm[i];
				while (curr != i) {
					cycle.add(curr);
					curr = perm[curr];
				}
				int p = (k / 4) % cycle.size();
				for (int x = 0; x < cycle.size(); x++) {
					ans[cycle.get(x)] = cycle.get(p);
					p = (p + 1) % cycle.size();
				}
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					board[i][j] = ans[before[i][j]];
			k %= 4;
			if (k > 0)
				down();
			if (k > 1)
				right();
			if (k > 2)
				up();
			if (k > 3)
				left();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					out.print(m[board[i][j]] + " ");
				out.print("\n");
			}
		}
		out.close();
	}

	public static void down() {
		for (int j = 0; j < n; j++) {
			ArrayList<Integer> temp = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (board[i][j] != 0)
					temp.add(board[i][j]);
				board[i][j] = 0;
			}
			int last = temp.size() - 1;
			for (int i = n - 1; i > -1; i--) {
				if (last != -1) {
					board[i][j] = temp.get(last);
					last--;
				} else {
					break;
				}
			}
		}
	}

	public static void right() {
		for (int i = 0; i < n; i++) {
			ArrayList<Integer> temp = new ArrayList<>();
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0)
					temp.add(board[i][j]);
				board[i][j] = 0;
			}
			int last = temp.size() - 1;
			for (int j = n - 1; j > -1; j--) {
				if (last != -1) {
					board[i][j] = temp.get(last);
					last--;
				} else {
					break;
				}
			}
		}
	}

	public static void up() {
		for (int j = 0; j < n; j++) {
			ArrayList<Integer> temp = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (board[i][j] != 0)
					temp.add(board[i][j]);
				board[i][j] = 0;
			}
			int last = 0;
			for (int i = 0; i < n; i++) {
				if (last != temp.size()) {
					board[i][j] = temp.get(last);
					last++;
				} else {
					break;
				}
			}
		}
	}

	public static void left() {
		for (int i = 0; i < n; i++) {
			ArrayList<Integer> temp = new ArrayList<>();
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0)
					temp.add(board[i][j]);
				board[i][j] = 0;
			}
			int last = 0;
			for (int j = 0; j < n; j++) {
				if (last != temp.size()) {
					board[i][j] = temp.get(last);
					last++;
				} else {
					break;
				}
			}
		}
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