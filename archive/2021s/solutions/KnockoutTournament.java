import java.util.*;
import java.io.*;

public class KnockoutTournament {

	static long mod = (long) 1e9 + 7;
	static int N = (int) 1e6 + 5;
	static long[] fact, ifact;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		n = (1 << n);
		fact = new long[N];
		ifact = new long[N];
		fact[0] = 1;
		for (int i = 1; i < N; ++i)
			fact[i] = (fact[i - 1] * i) % mod;
		ifact[N - 1] = pow(fact[N - 1], mod - 2);
		for (int i = N - 2; i >= 0; --i)
			ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; ++i)
			a[i] = sc.nextInt();
		Arrays.sort(a);
		long ans = a[n - 1] % mod;
		for (int i = 0; i < n; ++i)
			ans = (ans - a[i]) % mod;
		int log = 0;
		while ((1 << log) < n)
			++log;
		for (int i = 0; i < n; ++i) {
			long w = 0;
			long[] least = new long[log + 2];
			for (int d = log; d >= 0; --d) {
				int beat = (1 << d) - 1;
				least[d] = (C(i, beat) * iC(n - 1, beat)) % mod;
				long prob = (least[d] - least[d + 1]) % mod;
				w = (w + (prob * d) % mod) % mod;
			}
			ans = (ans + (w * a[i]) % mod) % mod;
		}
		System.out.println(ans);
		sc.close();
	}

	static long C(int x, int y) {
		if (x < y)
			return 0;
		return (fact[x] * ((ifact[x - y] * ifact[y]) % mod)) % mod;
	}

	static long iC(int x, int y) {
		if (x < y)
			return -1;
		return (ifact[x] * ((fact[x - y] * fact[y]) % mod)) % mod;
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