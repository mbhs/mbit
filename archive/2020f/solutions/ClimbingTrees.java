import java.util.*;
import java.io.*;

// By Ayush Varshney
public class ClimbingTrees {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		Long[] in = new Long[n];
		for (int i = 0; i < n; i++) {
			in[i] = sc.nextLong();
		}
		Arrays.sort(in);
		long curr = in[0], best = 0;
		for (int i = 0; i < n - 1; i++) {
			if (in[i + 1] - in[i] > k) {
				best = Math.max(curr, best);
				curr = in[i + 1];
			} else {
				curr += in[i + 1];
			}
		}
		best = Math.max(curr, best);
		System.out.println(best);
		sc.close();
	}

}