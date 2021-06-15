import java.util.*;
import java.io.*;

public class MapMatching {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int[][] p = new int[n][2], q = new int[n][2];
			int minp = Integer.MAX_VALUE, minpdex = 0;
			for (int i = 0; i < n; i++) {
				p[i][0] = sc.nextInt();
				p[i][1] = sc.nextInt();
				if (p[i][0] < minp) {
					minp = p[i][0];
					minpdex = i;
				}
			}
			int minq = Integer.MAX_VALUE, minqdex = 0;
			for (int i = 0; i < n; i++) {
				q[i][0] = sc.nextInt();
				q[i][1] = sc.nextInt();
				if (q[i][0] < minq) {
					minq = q[i][0];
					minqdex = i;
				}
			}
			int[] fact = new int[2];
			boolean ok = true;
			for (int i = 1; i < n; i++) {
				int[] v = new int[] { p[(i + minpdex) % n][0] - p[(i - 1 + minpdex) % n][0],
						p[(i + minpdex) % n][1] - p[(i - 1 + minpdex) % n][1] };
				int[] w = new int[] { q[(i + minqdex) % n][0] - q[(i - 1 + minqdex) % n][0],
						q[(i + minqdex) % n][1] - q[(i - 1 + minqdex) % n][1] };
				if (i == 1) {
					if (v[0] != 0 || w[0] != 0) {
						fact[0] = v[0] / gcd(v[0], w[0]);
						fact[1] = w[0] / gcd(v[0], w[0]);
					} else {
						fact[0] = v[1] / gcd(v[1], w[1]);
						fact[1] = w[1] / gcd(v[1], w[1]);
					}
				}
				if (((v[0] != 0 || w[0] != 0)
						&& (fact[0] != v[0] / gcd(v[0], w[0]) || fact[1] != w[0] / gcd(v[0], w[0])))
						|| ((v[1] != 0 || w[1] != 0)
								&& (fact[0] != v[1] / gcd(v[1], w[1]) || fact[1] != w[1] / gcd(v[1], w[1])))) {
					ok = false;
					break;
				}
			}
			if (ok)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
		sc.close();
	}

	public static int gcd(int n1, int n2) {
		if (n2 == 0) {
			return n1;
		}
		return gcd(n2, n1 % n2);
	}

}