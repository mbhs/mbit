/**
 * Author: Maxwell Zhang
 */
import java.util.*;

public class PenguinMayhem {

	/******************** START - CRT stuff ********************/
	static long x, y, g;

	static long gcd(long a, long b) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		long d = gcd(b, a % b);
		long x1 = x, y1 = y;
		x = y1;
		y = x1 - a / b * y1;
		return d;
	}

	static boolean solve(long a, long b, long c) {
		g = gcd(a, b);
		if (c % g != 0)
			return false;
		x *= c / g;
		y *= c / g;
		return true;
	}

	static long normalize(long x, long mod) {
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	static Pair crt(long a0, long m0, long a1, long m1) {
		if (!solve(m0, m1, a1 - a0))
			return new Pair(-1, -1); // no solution
		return new Pair(normalize(a0 + x % (m1 / g) * m0, m0 / g * m1), m0 / g * m1);
	}

	/******************** END - CRT stuff ********************/

	static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	static long swap(long a, long b) {
		return a;
	}

	static void swap(Penguin p, Penguin q) {
		p.sx = swap(q.sx, q.sx = p.sx);
		p.sy = swap(q.sy, q.sy = p.sy);
		p.vx = swap(q.vx, q.vx = p.vx);
		p.vy = swap(q.vy, q.vy = p.vy);
	}

	static Penguin[] a;
	static int h, w;
	static long t;

	static long solve(int i, int j) throws CloneNotSupportedException {
		// check x-direction
		// xt0 - initial time of intersection
		// xt - period of intersection
		// alwaysX - whether or not they always intersect
		Pair xt0 = new Pair(), xt = new Pair();
		boolean alwaysX = false;
		if (a[i].vx == a[j].vx) {
			// same x-velocity
			if (a[i].sx == a[j].sx)
				alwaysX = true; // always intersect
			else
				return 0; // never intersect
		} else {
			Penguin p = (Penguin) a[i].clone(), q = (Penguin) a[j].clone();
			// case 1: penguins are facing same direction
			if ((p.vx >= 0) == (q.vx >= 0)) {
				// for convenience, assume faster penguin is behind slower one
				if (p.vx < 0) {
					p.vx = -p.vx;
					q.vx = -q.vx;
					p.vx = swap(q.vx, q.vx = p.vx);
				}
				if (p.vx < q.vx)
					swap(p, q);
				if (p.sx > q.sx)
					p.sx -= w;
			}
			// case 2: penguins are facing opposite direction
			else {
				// for convenience, assume rightward penguin is to the left of leftward one
				if (p.vx < 0)
					swap(p, q);
				if (p.sx > q.sx)
					p.sx -= w;
			}
			xt0 = new Pair(q.sx - p.sx, p.vx - q.vx);
			xt = new Pair(w, p.vx - q.vx);
		}

		// check y-direction
		// yt0 - initial time of intersection
		// yt - period of intersection
		// alwaysY - whether or not they always intersect
		Pair yt0 = new Pair(), yt = new Pair();
		boolean alwaysY = false;
		if (a[i].vy == a[j].vy) {
			// same y-velocity
			if (a[i].sy == a[j].sy)
				alwaysY = true; // always intersect
			else
				return 0; // never intersect
		} else {
			Penguin p = (Penguin) a[i].clone(), q = (Penguin) a[j].clone();
			// case 1: penguins are facing same direction
			if ((p.vy >= 0) == (q.vy >= 0)) {
				// for convenience, assume faster penguin is behind slower one
				if (p.vy < 0) {
					p.vy = -p.vy;
					q.vy = -q.vy;
					p.vy = swap(q.vy, q.vy = p.vy);
				}
				if (p.vy < q.vy)
					swap(p, q);
				if (p.sy > q.sy)
					p.sy -= h;
			}
			// case 2: penguins are facing opposite direction
			else {
				// for convenience, assume upward penguin is beneath downward one
				if (p.vy < 0)
					swap(p, q);
				if (p.sy > q.sy)
					p.sy -= h;
			}
			yt0 = new Pair(q.sy - p.sy, p.vy - q.vy);
			yt = new Pair(h, p.vy - q.vy);
		}

		if (alwaysX) {
			long ll = lcm(yt0.second, yt.second);
			if (yt0.first * (ll / yt0.second) <= t * ll)
				return (t * ll - yt0.first * (ll / yt0.second)) / (yt.first * (ll / yt.second)) + 1;
			return 0;
		} else if (alwaysY) {
			long ll = lcm(xt0.second, xt.second);
			if (xt0.first * (ll / xt0.second) <= t * ll)
				return (t * ll - xt0.first * (ll / xt0.second)) / (xt.first * (ll / xt.second)) + 1;
			return 0;
		} else {
			// xt0 + xt * r = yt0 + yt * s, r and s are non-negative integers
			long ll = lcm(lcm(xt0.second, xt.second), lcm(yt0.second, yt.second));
			long xt0i = xt0.first * (ll / xt0.second), xti = xt.first * (ll / xt.second),
					yt0i = yt0.first * (ll / yt0.second), yti = yt.first * (ll / yt.second);
			Pair ret = crt(xt0i, xti, yt0i, yti);
			if (ret.first == -1)
				return 0;
			if (ret.first <= t * ll)
				return (t * ll - ret.first) / ret.second + 1;
			return 0;
		}
	}

	public static void main(String[] args) throws CloneNotSupportedException {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		h = sc.nextInt();
		w = sc.nextInt();
		a = new Penguin[n];
		for (int i = 0; i < n; i++)
			a[i] = new Penguin(sc.nextLong(), sc.nextLong(), sc.nextLong(), sc.nextLong());
		t = sc.nextLong();

		long ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ret += solve(i, j);

		System.out.println(ret);

		sc.close();

	}

	static class Pair {
		long first, second;

		Pair() {

		}

		Pair(long first, long second) {
			this.first = first;
			this.second = second;
		}

		public String toString() {
			return "(" + first + ", " + second + ")";
		}
	}

	static class Penguin implements Cloneable {
		long sx, sy, vx, vy;

		Penguin(long sx, long sy, long vx, long vy) {
			this.sx = sx;
			this.sy = sy;
			this.vx = vx;
			this.vy = vy;
		}

		public String toString() {
			return sx + ", " + sy + ", " + vx + ", " + vy;
		}

		public Object clone() throws CloneNotSupportedException {
			return super.clone();
		}
	}

}
