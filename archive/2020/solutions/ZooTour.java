import java.util.*;
import java.io.*;

// By Ayush Varshney
public class ZooTour {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		long[] in = new long[n];
		long prev = 0;
		for (int i = 0; i < n; i++) {
			in[i] = prev + sc.nextInt();
			prev = in[i];
		}
		for (int i = 0; i < q; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			int temp = Math.min(u, v);
			v = Math.max(u, v);
			u = temp;
			if (u == 1) {
				System.out.println(Math.min(in[v - 2], in[n - 1] - in[v - 2]));
			} else {
				System.out.println(Math.min(in[v - 2] - in[u - 2], in[n - 1] - (in[v - 2] - in[u - 2])));
			}
		}
		sc.close();
	}

}