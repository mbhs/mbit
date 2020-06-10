/**
 * Author: Maxwell Zhang
 */
import java.util.*;

public class GorillaGrouping {

	final static int MOD = 1000000007;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(), k = sc.nextInt();
		int[] a = new int[n];
		HashSet<Integer> st = new HashSet<>();
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			st.add(a[i]);
		}

		int[] dp = new int[n + 1];
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

		long ret = 1;
		Arrays.sort(a);
		for (int i = 0; i < n; i++)
			if (st.contains(a[i])) {
				int x = a[i], len = 0;
				while (st.contains(x)) {
					st.remove(x);
					x += k;
					len++;
				}
				ret = (ret * dp[len]) % MOD;
			}
		ret = (ret + MOD - 1) % MOD;

		System.out.println(ret);

		sc.close();
	}

}
