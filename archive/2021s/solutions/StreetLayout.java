import java.util.*;
import java.io.*;

public class StreetLayout {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long m = sc.nextLong();
		long l = sc.nextLong();
		Long[] in = new Long[n];
		for (int i = 0; i < n; i++) {
			in[i] = sc.nextLong();
		}
		Arrays.sort(in);
		long lp = 1, rp = 1000000005;

		while (lp < rp) {
			long mp = (lp + rp) / 2;
			long unplaced = m;
			unplaced -= Math.min(in[0] - 1, mp);
			unplaced -= Math.min(l - in[n - 1], mp);
			for (int i = 0; i < n - 1; i++) {
				unplaced -= Math.min(2 * mp, in[i + 1] - in[i] - 1);
			}
			if (unplaced > 0) {
				lp = mp + 1;
			} else {
				rp = mp;
			}
		}

		System.out.println(lp);

		sc.close();
	}

}