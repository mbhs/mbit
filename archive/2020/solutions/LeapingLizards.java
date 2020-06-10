import java.util.*;
import java.io.*;

// By Ayush Varshney
public class LeapingLizards {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] in = new int[n];
		for (int i = 0; i < n; i++) {
			in[i] = sc.nextInt();
		}
		ArrayList<Integer>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
			double maxSlope = 0;
			for (int j = i + 1; j < n; j++) {
				double currSlope = (in[j] - in[i]) / ((double) j - i);
				if (currSlope >= maxSlope || j == i + 1) {
					adj[i].add(j);
					maxSlope = currSlope;
				}
			}
		}
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] { 0, 1 });
		boolean[] vis = new boolean[n];
		while (!q.isEmpty()) {
			int[] curr = q.poll();
			vis[curr[0]] = true;
			if (curr[0] == n - 1) {
				System.out.println(curr[1]);
				break;
			}
			for (int i : adj[curr[0]]) {
				if (vis[i]) {
					continue;
				}
				q.add(new int[] { i, curr[1] + 1 });
			}
		}
		sc.close();
	}

}