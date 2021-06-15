import java.util.*;
import java.io.*;

public class CytusCraze {

	static int mod = (int) 1e9 + 7;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int L = 61;
		long n = sc.nextLong(), k = sc.nextLong();
		long[] a = new long[L];
		for (int i = 0; i < L; i++)
			a[i] = n / (1L << i);
		for (int i = 0; i < L - 2; i++)
			a[i] -= a[i + 1];
		int top = 0;
		for (int i = 0; i < L; i++)
			if (a[i] != 0)
				top = i;
		k = Math.min(k, (1L << (top + 1)) - 1);
		long ans = ((k + 1) + mod) % mod;
		for (int i = 0; i <= top; i++)
			ans = (ans * pow(2, a[i] - 1)) % mod;
		System.out.println(ans);
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