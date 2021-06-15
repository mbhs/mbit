import java.util.*;
import java.io.*;

public class LuigisMansion {

	static long INF = (long) 1e18;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		OutputWriter out = new OutputWriter(System.out);
		int n = sc.nextInt();
		long den = sc.nextLong();
		long[] a = new long[n + 1];
		long[] p = new long[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = sc.nextLong();
			p[i] = p[i - 1] + a[i];
		}
		long num = 0;
		long[][] dp = new long[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			num += a[i] * i * 3;
		}
		ConvexHullDeque[] C = new ConvexHullDeque[n + 1];
		for (int i = 1; i <= n; i++) {
			dp[0][i] = 2 * i * (den - p[i]);
			C[i] = new ConvexHullDeque();
			C[i].add(-2 * p[0], dp[0][i]);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				dp[i][j] = C[i].query(j) + 2 * j * (den - p[i] - p[j]);
				C[j].add(-2 * p[i], dp[i][j]);
			}
		}

		num += dp[n][n];
		long g = gcd(num, den);
		num /= g;
		den /= g;

		out.print(num + "/" + den + "\n");
		out.close();
	}

	static long gcd(long a, long b) {
		if (a > b)
			return gcd(b, a);
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	static class Line {
		public long a, b, lst;

		public Line(long a, long b, long lst) {
			this.a = a;
			this.b = b;
			this.lst = lst;
		}

		long eval(long x) {
			return a * x + b;
		}

		public int compareTo(Line y) {
			return (int) Math.max(-100, Math.min(100, (this.a - y.a)));
		}

		long floor_div(long a, long b) {
			if ((a ^ b) < 0 && (a % b != 0))
				return a / b - 1;
			return a / b;
		}

		long bet(Line y) {
			return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);
		}
	}

	static class ConvexHullDeque {
		ArrayDeque<Line> lines;

		public ConvexHullDeque() {
			lines = new ArrayDeque<Line>();
		}

		public void add_back(Line L) {
			while (true) {
				Line a = lines.pollLast();
				a.lst = a.bet(L);
				if (lines.size() != 0 && lines.peekLast().lst >= a.lst) {
					continue;
				}
				lines.addLast(a);
				break;
			}
			L.lst = INF;
			lines.addLast(L);
		}

		public void add_front(Line L) {
			while (true) {
				if (lines.size() == 0) {
					L.lst = INF;
					break;
				}
				if ((L.lst = L.bet(lines.peekFirst())) >= lines.peekFirst().lst) {
					lines.pollFirst();
				} else {
					break;
				}
			}
			lines.addFirst(L);
		}

		public void add(long a, long b) {
			a = -a;
			b = -b;
			if (lines.size() == 0 || a <= lines.peekFirst().a) {
				add_front(new Line(a, b, 0));
			} else {
				add_back(new Line(a, b, 0));
			}
		}

		public long query(long x) {
			while (lines.peekFirst().lst < x) {
				lines.pollFirst();
			}
			return -lines.peekFirst().eval(x);
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