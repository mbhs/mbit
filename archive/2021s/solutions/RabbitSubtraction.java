import java.util.*;
import java.io.*;

public class RabbitSubtraction {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int x = 1;
		while (Math.pow(2, x) <= n) {
			x++;
		}
		int[] p2 = new int[x + 5];
		for (int i = 0; i < x + 5; i++) {
			p2[i] = (int) Math.pow(2, i);
		}
		long[][] dp = new long[n][20];
		for (int i = 0; i < n; i++) {
			dp[i][0] = a[i];
		}
		for (int t = 0; t < x - 1; t++) {
			for (int i = 0; i < n; i++) {
				dp[i][t + 1] = dp[i][t] - dp[(i + p2[t]) % n][t];
			}
		}
		long best = Long.MIN_VALUE;
		int startsign = -1;
		if (Integer.bitCount(n) % 2 == 1)
			startsign = 1;
		for (int i = 0; i < n; i++) {
			int sign = startsign;
			long curr = 0;
			int k = n;
			int t = 0;
			int iadd = n;
			while (k > 0) {
				if (k % 2 == 1) {
					iadd -= p2[t];
					curr += sign * dp[(i + iadd) % n][t];
					sign *= -1;
				}
				t += 1;
				k >>= 1;
			}
			best = Math.max(best, curr);
		}
		System.out.println(best);
		sc.close();
	}

}