import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Locked {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong() + 1;
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
		}
		long[] neg = new long[n + 1];
		long[] pos = new long[n + 1];
		for (int i = 0; i < n + 1; i++) {
			neg[i] = i * k;
			pos[i] = i * k;
		}
		long bef = 0;
		for (int i = 0; i < n; i++) {
			long[] nneg = new long[n + 1];
			long[] npos = new long[n + 1];
			if (a[i] >= bef) {
				long minpos = Long.MAX_VALUE;
				for (int j = 0; j < n + 1; j++) {
					minpos = Math.min(minpos, pos[j]);
				}
				long minneg = Long.MAX_VALUE;
				for (int j = 1; j < n + 1; j++) {
					minneg = Math.min(minneg, neg[j]);
				}
				long bb = Math.min(minneg, minpos);
				long best = bb;
				for (int j = 0; j < n + 1; j++) {
					best = Math.min(best, pos[j] - (bef + j * k));
					npos[j] = a[i] + j * k + best;
				}
				best = bb;
				for (int j = 1; j < n + 1; j++) {
					nneg[j] = -a[i] + j * k + best;
					best = Math.min(best, neg[j] - (j * k - bef));
				}
				best = pos[n];
				for (int j = n - 1; j > -1; j--) {
					npos[j] = Math.min(npos[j], best);
					best = Math.min(best, pos[j]);
				}
				best = neg[n];
				for (int j = n; j > 0; j--) {
					best = Math.min(best, neg[j]);
					nneg[j] = Math.min(nneg[j], best);
				}
			} else {
				long minpos = Long.MAX_VALUE;
				for (int j = 0; j < n + 1; j++) {
					minpos = Math.min(minpos, pos[j]);
				}
				long minneg = Long.MAX_VALUE;
				for (int j = 1; j < n + 1; j++) {
					minneg = Math.min(minneg, neg[j]);
				}
				long bb = Math.min(minneg, minpos);
				long best = bb;
				for (int j = 0; j < n + 1; j++) {
					npos[j] = a[i] + j * k + best;
					best = Math.min(best, pos[j] - (bef + j * k));
				}
				best = bb;
				for (int j = 1; j < n + 1; j++) {
					best = Math.min(best, neg[j] - (j * k - bef));
					nneg[j] = -a[i] + j * k + best;
				}
				best = pos[n];
				for (int j = n; j > -1; j--) {
					best = Math.min(best, pos[j]);
					npos[j] = Math.min(npos[j], best);
				}
				best = neg[n];
				for (int j = n - 1; j > 0; j--) {
					nneg[j] = Math.min(nneg[j], best);
					best = Math.min(best, neg[j]);
				}
			}
			pos = npos;
			neg = nneg;
			bef = a[i];
		}
		long minpos = Long.MAX_VALUE;
		for (int j = 0; j < n + 1; j++) {
			minpos = Math.min(minpos, pos[j]);
		}
		long minneg = Long.MAX_VALUE;
		for (int j = 1; j < n + 1; j++) {
			minneg = Math.min(minneg, neg[j]);
		}
		System.out.println(Math.min(minneg, minpos));
		sc.close();
	}

}