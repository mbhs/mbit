/**
 * Author: Maxwell Zhang
 */
import java.util.*;

public class PlaylistShuffle {

	static int n, b, x, y;

	static double f(int r) {
		int cntLeft = Math.min(r, b - 1), cntRight = Math.min(r, n - b);
		long totR = (long) cntLeft * (cntLeft + 1) / 2 + (long) cntRight * (cntRight + 1) / 2;
		return (double) (totR * x + (long) (n - cntLeft - cntRight - 1) * y) / (cntLeft + cntRight + 1);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		b = sc.nextInt();
		x = sc.nextInt();
		y = sc.nextInt();

		int l = 0, r = n;
		while (l < r) {
			int m = (l + r) / 2;
			if (f(m) <= f(m + 1))
				r = m;
			else
				l = m + 1;
		}

		System.out.printf("%.10f\n", f(l));

		sc.close();

	}

}
