
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class CupcakeDistribution {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        long[] s = new long[n];
        double[] psum = new double[n], sqsum = new double[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
            psum[i] = (i > 0 ? psum[i-1] : 0) + s[i];
            sqsum[i] = (i > 0 ? sqsum[i-1] : 0) + s[i] * s[i];
        }
        double[] dp = new double[n];
        for (int i = k-1; i < n; i++) {
            double avg = psum[i] / (i + 1);
            dp[i] = (i+1)*avg*avg - 2*avg*psum[i] + sqsum[i];
            for (int j = i - k; j >= k - 1; j--) {
                avg = (psum[i] - psum[j]) / (i - j);
                dp[i] = Math.min(dp[i], dp[j] + (i-j)*avg*avg - 2*avg*(psum[i]-psum[j]) + sqsum[i]-sqsum[j]);
            }
        }
        System.out.println((long) dp[n-1]);
        sc.close();
    }

}