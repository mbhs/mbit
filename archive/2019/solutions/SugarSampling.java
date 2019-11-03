import java.io.*;
import java.util.*;

public class SugarSampling {

	static final int MOD = 1000000007;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[][] numPaths = new int[n][n];
		int[][][] dp = new int[n][n][n];
		numPaths[0][0] = 1;
		for (int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j=0; j<n; j++) {
				int a = Integer.parseInt(st.nextToken()) - 1;
				if (i > 0) numPaths[i][j] = (numPaths[i][j] + numPaths[i-1][j]) % MOD;
				if (j > 0) numPaths[i][j] = (numPaths[i][j] + numPaths[i][j-1]) % MOD;
				for (int k=0; k<n; k++) {
					if (a == k)
						dp[i][j][k] = numPaths[i][j];
					else {
						if (i > 0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
						if (j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
					}
				}
			}
		}
		
		for (int i=0; i<n; i++)
			System.out.println(i+1 + " " + dp[n-1][n-1][i]);

	}

}