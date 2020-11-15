import java.util.*;
import java.io.*;

// By Ayush Varshney
public class BuildingAtlantis {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		Point[] v = new Point[m];
		for (int i = 0; i < m; i++) {
			v[i] = new Point(sc.nextInt(), sc.nextInt(), sc.nextDouble());
		}
		Arrays.sort(v);
		double lo = 0, hi = 1e15, mid = (hi + lo) / 2;
		while (Math.abs(1 - lo / hi) > .0000001) {
			mid = (hi + lo) / 2;
			int ind = 0;
			PriorityQueue<Point2> h = new PriorityQueue<>();
			boolean works = true;
			for (int p = 1; p < n + 1; p++) {
				while (ind < m && v[ind].l == p) {
					h.add(new Point2(v[ind].r, v[ind].a));
					ind++;
				}
				double x = mid;
				while (x > 0 && h.size() > 0) {
					Point2 r = h.poll();
					if (r.r < p) {
						works = false;
						break;
					}
					if (r.a > x) {
						h.add(new Point2(r.r, r.a - x));
						x = 0;
					} else {
						x -= r.a;
					}
				}

				if (!works) {
					break;
				}
			}
			if (h.size() > 0) {
				works = false;
			}
			if (works)
				hi = mid;
			else
				lo = mid;
		}
		double H = mid;
		lo = 0;
		hi = 1e15;
		mid = (hi + lo) / 2;
		while (Math.abs(1 - lo / hi) > .0000001) {
			mid = (hi + lo) / 2;
			int ind = 0;
			PriorityQueue<Point2> h = new PriorityQueue<>();
			boolean works = true;
			for (int p = 1; p < n + 1; p++) {
				while (ind < m && v[ind].l == p) {
					h.add(new Point2(v[ind].r, v[ind].a));
					ind++;
				}
				double x = mid;
				while (x > 0 && h.size() > 0) {
					Point2 r = h.poll();
					if (r.r < p) {
						continue;
					}
					if (r.a >= x) {
						h.add(new Point2(r.r, r.a - x));
						x = 0;
					} else {
						x -= r.a;
					}
				}

				if (x > 0) {
					works = false;
					break;
				}
			}
			if (works)
				lo = mid;
			else
				hi = mid;
		}
		double L = mid;
		System.out.println(L / H);
		sc.close();
	}

	static class Point implements Comparable<Point> {
		int l, r;
		double a;

		Point(int l, int r, double a) {
			this.l = l;
			this.r = r;
			this.a = a;
		}

		@Override
		public int compareTo(Point o) {
			if (this.l == o.l)
				return this.r - o.r;
			return this.l - o.l;
		}

		public boolean equals(Object obj) {
			if (obj instanceof Point) {
				Point other = (Point) obj;
				return l == other.l && r == other.r && a == other.a;
			}
			return false;
		}

	}

	static class Point2 implements Comparable<Point2> {
		int r;
		double a;

		Point2(int r, double a) {
			this.r = r;
			this.a = a;
		}

		@Override
		public int compareTo(Point2 o) {
			if (this.r == o.r)
				return (int) (this.a - o.a);
			return this.r - o.r;
		}

		public boolean equals(Object obj) {
			if (obj instanceof Point2) {
				Point2 other = (Point2) obj;
				return r == other.r && a == other.a;
			}
			return false;
		}

	}

}