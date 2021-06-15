import java.util.*;
import java.io.*;

public class KirbysBuffet {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		OutputWriter out = new OutputWriter(System.out);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int C = 2000;
		int[] in = new int[n];
		for (int i = 0; i < n; i++)
			in[i] = sc.nextInt();
		long[][] dp = new long[n / C + 3][1 << 17];
		for (int i = 0; i < n / C + 3; i++) {
			Arrays.fill(dp[i], (1 << 30) - 1);
		}
		for (int i = 0; i * C < n; i++) {
			for (int j = i * C; j <= Math.min(n - 1, (i + 1) * C - 1); j++) {
				dp[i][in[j]] = in[j];
			}

			for (int j = (1 << 17) - 1; j >= 0; j--) {
				for (int k = 0; k < 17; k++) {
					if ((j & (1 << k)) == 0) {
						dp[i][j] &= dp[i][j | (1 << k)];
					}
				}
			}
		}
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt(), r = sc.nextInt(), x = sc.nextInt();
			--l;
			--r;

			int v = (1 << 30) - 1;
			for (int j = 0; j * C < n; j++) {
				int lv = j * C, rv = Math.min(n - 1, (j + 1) * C - 1);

				if (l <= lv && rv <= r)
					v &= dp[j][x];
				else {
					lv = Math.max(lv, l);
					rv = Math.min(rv, r);
					for (int k = lv; k <= rv; k++) {
						if ((in[k] & x) == x) {
							v &= in[k];
						}
					}
				}
			}

			out.print(v == x ? "YES\n" : "NO\n");
		}
		out.close();
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