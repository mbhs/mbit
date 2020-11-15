import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Cathedral {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		long[] psum = new long[n + 1];
		for (int i = 1; i < n + 1; i++) {
			psum[i] = psum[i - 1] + sc.nextLong();
		}
		
		while (q-- > 0) {
			int x = sc.nextInt(), k = sc.nextInt();
			int y = x + 2 * k - 1, l = 0, r = k;
			long tot = psum[y] - psum[x - 1];
			long ans = (long)1e9;
			while (l < r) {
				int m = (l + r) / 2;
				long cur = psum[x + k - m - 1] - psum[x - 1] + psum[y] - psum[y - m];
				ans = Math.min(ans, Math.abs(cur * 2 - tot));
				if (cur <= tot - cur) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			System.out.println(ans);
		}
		sc.close();
	}

}