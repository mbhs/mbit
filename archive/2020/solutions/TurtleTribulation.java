import java.util.*;
import java.io.*;

// By Ayush Varshney
public class TurtleTribulation {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), z = sc.nextInt();
		double k = sc.nextDouble();
		Point[] in = new Point[n];
		for (int i = 0; i < n; i++)
			in[i] = new Point(sc.nextInt() - 1, sc.nextInt() - 1);
		Arrays.sort(in);
		int[][] dp = new int[n][z];
		Arrays.fill(dp[0], 99999999);
		dp[0][in[0].a] = 0;
		for (int i = 1; i < n; i++) {
			Deque<Point> d = new ArrayDeque<>();
			for (int j = 0, l = 0; j < z; j++) {
				while (l <= Math.min(j + (int) ((in[i].b - in[i - 1].b) / k), z - 1)) {
					while (!d.isEmpty() && d.peekLast().a >= dp[i - 1][l])
						d.pollLast();
					d.addLast(new Point(dp[i - 1][l], l++));
				}
				if (d.peekFirst().b == Math.max(j - (int) ((in[i].b - in[i - 1].b) / k), 0) - 1)
					d.pollFirst();
				dp[i][j] = Math.abs(in[i].a - j) + d.peekFirst().a;
			}
		}
		System.out.println(dp[n - 1][in[n - 1].a]);
		sc.close();
	}

	static class Point implements Comparable<Point> {
		int a;
		int b;

		Point(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Point o) {
			return this.b - o.b;
		}
	}
}