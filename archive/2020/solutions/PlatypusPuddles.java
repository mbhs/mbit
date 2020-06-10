import java.util.*;
import java.io.*;

// By Ayush Varshney
public class PlatypusPuddles {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		boolean[] vis = new boolean[n * n];
		long[] grid = new long[n * n];
		for (int i = 0; i < n * n; i++) {
			grid[i] = sc.nextLong();
		}

		long ans = 0;

		PriorityQueue<Point> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1) {
				for (int j = 0; j < n; j++) {
					pq.add(new Point(grid[i * n + j], i, j));
				}
			} else {
				pq.add(new Point(grid[i * n + 0], i, 0));
				pq.add(new Point(grid[i * n + n - 1], i, n - 1));
			}
		}

		while (!pq.isEmpty()) {
			Point p = pq.poll();
			long val = p.a;
			int i = p.b;
			int j = p.c;
			if (vis[i * n + j])
				continue;
			vis[i * n + j] = true;
			ans += Math.max(0, val - grid[i * n + j]);
			long newval = Math.max(grid[i * n + j], val);
			if (i > 0)
				pq.add(new Point(newval, i - 1, j));
			if (i < n - 1)
				pq.add(new Point(newval, i + 1, j));
			if (j > 0)
				pq.add(new Point(newval, i, j - 1));
			if (j < n - 1)
				pq.add(new Point(newval, i, j + 1));
		}
		System.out.println(ans);
		sc.close();
	}
	
	static class Point implements Comparable<Point> {
		long a;
		int b, c;

		Point(long a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}

		@Override
		public int compareTo(Point o) {
			if (this.a == o.a) {
				if (this.b == o.b) {
					return this.c - o.c;
				} else {
					if (this.b > o.b) {
						return 1;
					}
					return -1;
				}
			} else {
				if (this.a > o.a) {
					return 1;
				}
				return -1;
			}
		}
	}

}