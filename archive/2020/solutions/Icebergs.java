import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Icebergs {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] x = new long[n];
		long[] y = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}
		ArrayList<Point>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				adj[i].add(new Point((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), j));
			}
			Collections.sort(adj[i]);
		}
		boolean[] vis = new boolean[n];
		int[] ptr = new int[n];
		int shot = 0, curr = -1;
		while (shot != n - 1) {
			curr += 1;
			curr %= n;
			if (vis[curr])
				continue;
			while (vis[adj[curr].get(ptr[curr]).b]) {
				ptr[curr]++;
			}
			vis[adj[curr].get(ptr[curr]).b] = true;
			shot++;
		}
		System.out.println(curr + 1);
		sc.close();
	}

	static class Point implements Comparable<Point> {
		long a;
		int b;

		Point(long a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Point o) {
			if (this.a != o.a) {
				if (this.a > o.a)
					return 1;
				else
					return -1;
			}
			return this.b - o.b;
		}

	}

}