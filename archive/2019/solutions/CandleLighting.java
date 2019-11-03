import java.io.*;
import java.util.*;

public class CandleLighting {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		int a[][] = new int[n][m], prefixSum[][] = new int[n+1][m+1];
		for (int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<m; j++)
				a[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int q = Integer.parseInt(br.readLine());
		for (int i=0; i<q; i++) {
			st = new StringTokenizer(br.readLine());
			int i1 = Integer.parseInt(st.nextToken()), j1 = Integer.parseInt(st.nextToken()), i2 = Integer.parseInt(st.nextToken()), j2 = Integer.parseInt(st.nextToken());
			prefixSum[i1-1][j1-1]++;
			prefixSum[i1-1][j2]--;
			prefixSum[i2][j1-1]--;
			prefixSum[i2][j2]++;
		}
		
		int ret = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				if (i > 0)
					prefixSum[i][j] += prefixSum[i-1][j];
				if (j > 0)
					prefixSum[i][j] += prefixSum[i][j-1];
				if (i > 0 && j > 0)
					prefixSum[i][j] -= prefixSum[i-1][j-1];
				ret += (a[i][j] + prefixSum[i][j]) % 2;
			}
		
		System.out.println(ret);

	}

}