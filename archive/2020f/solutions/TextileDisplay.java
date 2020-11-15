import java.util.*;
import java.io.*;

// By Ayush Varshney
public class TextileDisplay {
	static long mod = (long) 1e9 + 7;
	static int n, m;
	static long[] fac, invfac;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();

		fac = new long[n + 1];
		Arrays.fill(fac, 1);
		invfac = new long[n + 1];
		Arrays.fill(invfac, 1);

		for (int i = 1; i < n + 1; i++) {
			fac[i] = (fac[i - 1] * (long) i) % mod;
		}

		invfac[n] = pow(fac[n], mod - 2);
		for (int i = n - 1; i > -1; i--) {
			invfac[i] = (invfac[i + 1] * (long) (i + 1)) % mod;
		}
		
		long out = 0;
		for (int i = 0; i < m; i++) {
			out = (out + comp(sc.nextInt())) % mod;
		}
		System.out.println(out);
		sc.close();
	}

	static long choose(int a, int b) {
		if (b > a)
			return 0;
		return (((fac[a] * invfac[b]) % mod) * invfac[a - b]) % mod;
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

	static long comp(int k) {
		return (((((long) n * choose(n, k) - choose(n, k + 1)) % mod) * fac[k]) % mod * fac[n - k]) % mod;
	}

}