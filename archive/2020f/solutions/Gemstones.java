import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Gemstones {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] grid = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				grid[i][j] = sc.nextInt();
			}
		}
		int[][] oneH = new int[n][n];
		int[][] twoH = new int[n][n];
		int[][] thrH = new int[n][n];
		int[][] oneV = new int[n][n];
		int[][] twoV = new int[n][n];
		int[][] thrV = new int[n][n];
		int[][] oneD = new int[n][n];
		int[][] twoD = new int[n][n];
		int[][] thrD = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (j == 0) {
					if (grid[i][j] == 1) {
						oneH[i][j] = 1;
					} else if (grid[i][j] == 2) {
						twoH[i][j] = 1;
					} else if (grid[i][j] == 3) {
						thrH[i][j] = 1;
					}
				} else {
					if (grid[i][j] == 1) {
						oneH[i][j] = oneH[i][j - 1] + 1;
						twoH[i][j] = twoH[i][j - 1];
						thrH[i][j] = thrH[i][j - 1];
					} else if (grid[i][j] == 2) {
						oneH[i][j] = oneH[i][j - 1];
						twoH[i][j] = twoH[i][j - 1] + 1;
						thrH[i][j] = thrH[i][j - 1];
					} else if (grid[i][j] == 3) {
						oneH[i][j] = oneH[i][j - 1];
						twoH[i][j] = twoH[i][j - 1];
						thrH[i][j] = thrH[i][j - 1] + 1;
					}
				}
			}
			for (int j = i; j < n; j++) {
				if (j == i) {
					if (grid[j][i] == 1) {
						oneV[j][i] = 1;
					} else if (grid[j][i] == 2) {
						twoV[j][i] = 1;
					} else if (grid[j][i] == 3) {
						thrV[j][i] = 1;
					}
				} else {
					if (grid[j][i] == 1) {
						oneV[j][i] = oneV[j - 1][i] + 1;
						twoV[j][i] = twoV[j - 1][i];
						thrV[j][i] = thrV[j - 1][i];
					} else if (grid[j][i] == 2) {
						oneV[j][i] = oneV[j - 1][i];
						twoV[j][i] = twoV[j - 1][i] + 1;
						thrV[j][i] = thrV[j - 1][i];
					} else if (grid[j][i] == 3) {
						oneV[j][i] = oneV[j - 1][i];
						twoV[j][i] = twoV[j - 1][i];
						thrV[j][i] = thrV[j - 1][i] + 1;
					}
				}
			}
			for (int j = 0; j < n - i; j++) {
				if (j == 0) {
					if (grid[i][j] == 1) {
						oneD[i][j] = 1;
					} else if (grid[i][j] == 2) {
						twoD[i][j] = 1;
					} else if (grid[i][j] == 3) {
						thrD[i][j] = 1;
					}
				} else {
					if (grid[i + j][j] == 1) {
						oneD[i + j][j] = oneD[i + j - 1][j - 1] + 1;
						twoD[i + j][j] = twoD[i + j - 1][j - 1];
						thrD[i + j][j] = thrD[i + j - 1][j - 1];
					} else if (grid[i + j][j] == 2) {
						oneD[i + j][j] = oneD[i + j - 1][j - 1];
						twoD[i + j][j] = twoD[i + j - 1][j - 1] + 1;
						thrD[i + j][j] = thrD[i + j - 1][j - 1];
					} else if (grid[i + j][j] == 3) {
						oneD[i + j][j] = oneD[i + j - 1][j - 1];
						twoD[i + j][j] = twoD[i + j - 1][j - 1];
						thrD[i + j][j] = thrD[i + j - 1][j - 1] + 1;
					}
				}
			}
		}
		long[][] dp = new long[n][n];
		for (int sz = 1; sz < n; sz++) {
			long[][] new1 = new long[n][n];
			for (int i = 0; i < n - sz; i++) {
				for (int j = 0; j < i + 1; j++) {
					if (j > 0) {
						if (i > 0) {
							new1[i][j] = Math.max(new1[i][j],
									dp[i][j] + Math.max(oneH[i + sz][j + sz] - oneH[i + sz][j - 1],
											Math.max(twoH[i + sz][j + sz] - twoH[i + sz][j - 1],
													thrH[i + sz][j + sz] - thrH[i + sz][j - 1])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j + 1] + Math.max(
									oneV[i + sz][j] - oneV[i - 1][j],
									Math.max(twoV[i + sz][j] - twoV[i - 1][j], thrV[i + sz][j] - thrV[i - 1][j])));
							new1[i][j] = Math.max(new1[i][j],
									dp[i + 1][j] + Math.max(oneD[i + sz][j + sz] - oneD[i - 1][j - 1],
											Math.max(twoD[i + sz][j + sz] - twoD[i - 1][j - 1],
													thrD[i + sz][j + sz] - thrD[i - 1][j - 1])));
						} else {
							new1[i][j] = Math.max(new1[i][j],
									dp[i][j] + Math.max(oneH[i + sz][j + sz] - oneH[i + sz][j - 1],
											Math.max(twoH[i + sz][j + sz] - twoH[i + sz][j - 1],
													thrH[i + sz][j + sz] - thrH[i + sz][j - 1])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j + 1]
									+ Math.max(oneV[i + sz][j], Math.max(twoV[i + sz][j], thrV[i + sz][j])));
							new1[i][j] = Math.max(new1[i][j],
									dp[i + 1][j] + Math.max(oneD[i + sz][j + sz] - oneD[i - 1][j - 1],
											Math.max(twoD[i + sz][j + sz] - twoD[i - 1][j - 1],
													thrD[i + sz][j + sz] - thrD[i - 1][j - 1])));
						}
					} else {
						if (i > 0) {
							new1[i][j] = Math.max(new1[i][j], dp[i][j] + Math.max(oneH[i + sz][j + sz],
									Math.max(twoH[i + sz][j + sz], thrH[i + sz][j + sz])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j + 1] + Math.max(
									oneV[i + sz][j] - oneV[i - 1][j],
									Math.max(twoV[i + sz][j] - twoV[i - 1][j], thrV[i + sz][j] - thrV[i - 1][j])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j] + Math.max(oneD[i + sz][j + sz],
									Math.max(twoD[i + sz][j + sz], thrD[i + sz][j + sz])));
						} else {
							new1[i][j] = Math.max(new1[i][j], dp[i][j] + Math.max(oneH[i + sz][j + sz],
									Math.max(twoH[i + sz][j + sz], thrH[i + sz][j + sz])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j + 1]
									+ Math.max(oneV[i + sz][j], Math.max(twoV[i + sz][j], thrV[i + sz][j])));
							new1[i][j] = Math.max(new1[i][j], dp[i + 1][j] + Math.max(oneD[i + sz][j + sz],
									Math.max(twoD[i + sz][j + sz], thrD[i + sz][j + sz])));
						}
					}
				}
			}
			dp = new1;
		}
		System.out.println(dp[0][0]);
		sc.close();
	}

}