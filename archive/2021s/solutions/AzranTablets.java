import java.util.*;
import java.io.*;

public class AzranTablets {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = s.length();
		int[] dp = new int[n];
		int[] let = new int[26];
		Arrays.fill(let, 999999999);
		let[s.charAt(0) - 'a'] = 0;
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			int x = s.charAt(i) - 'a';
			let[x] = Math.min(let[x], dp[i - 1]);
			dp[i] = let[x] + 1;
		}
		System.out.println(dp[n - 1]);
		sc.close();
	}

}