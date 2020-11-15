import java.util.*;
import java.io.*;

// By Ayush Varshney
public class TheDuplicator {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n], b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
		}
		long pairs = (long) n * (long) (n - 1) / 2;
		HashMap<Integer, Integer> c1 = new HashMap<>();
		HashMap<Integer, Integer> c2 = new HashMap<>();
		HashMap<Point, Integer> c3 = new HashMap<>();
		for (int i = 0; i < n; i++) {
			c1.putIfAbsent(a[i], 0);
			c2.putIfAbsent(b[i], 0);
			c3.putIfAbsent(new Point(a[i], b[i]), 0);
			pairs += c3.get(new Point(a[i], b[i])) - c1.get(a[i]) - c2.get(b[i]);
			c1.compute(a[i], ((k, v) -> v + 1));
			c2.compute(b[i], ((k, v) -> v + 1));
			c3.compute(new Point(a[i], b[i]), ((k, v) -> v + 1));
		}
		System.out.println(pairs);
		sc.close();
	}

	static class Point {
		int a;
		int b;

		Point(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public boolean equals(Object obj) {
			if (obj instanceof Point) {
				Point other = (Point) obj;
				return a == other.a && b == other.b;
			}
			return false;
		}

		public int hashCode() {
			return 31 * a + b;
		}

	}

}