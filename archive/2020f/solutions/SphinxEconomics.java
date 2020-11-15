import java.util.*;
import java.io.*;

// By Ayush Varshney
public class SphinxEconomics {
	static long mod = (long) 1e9 + 7;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), q = sc.nextInt();
		if (q > n) {
			System.out.println(1);
		}
		long[] dp = new long[n + 1];
		dp[0] = 1;
		long s = 1;
		for (int i = 1; i < n + 1; i++) {
			dp[i] = s;
			s += dp[i];
			if (i >= q - 1)
				s -= dp[i - (q - 1)];
			s = (s + mod) % mod;
		}
		System.out.println((pow(dp[n], mod - 2) * pow(2, n - 1)) % mod);
		sc.close();
	}

	static long pow(long a, long b) {
		if (b == 0)
			return 1L;
		long val = pow(a, b / 2);
		if (b % 2 == 0)
			return val * val % mod;
		else
			return val * val % mod * a % mod;
	}
}