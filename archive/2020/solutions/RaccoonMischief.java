import java.util.*;
import java.io.*;

// By Ayush Varshney
public class RaccoonMischief {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int[] in = new int[n];
		ArrayList<int[]>[] a = new ArrayList[n];
		ArrayList<int[]>[] b = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			in[i] = sc.nextInt();
			a[i] = new ArrayList<>();
			b[i] = new ArrayList<>();
		}
		for (int i = 0; i < q; i++) {
			int l = sc.nextInt() - 1, r = sc.nextInt() - 1, x = sc.nextInt();
			a[l].add(new int[] { i, x });
			b[r].add(a[l].get(a[l].size() - 1));
		}

		TreeSet<int[]> curr = new TreeSet<>(new cmpSL());
		for (int i = 0; i < n; i++) {
			for (int[] j : a[i])
				curr.add(j);
			if (curr.size() == 0) {
				System.out.print(in[i] + " ");
			} else if (in[i] == 0 && curr.size() % 2 == 1) {
				int[] temp = curr.pollLast();
				System.out.print(temp[1] + " ");
				curr.add(temp);
			} else if (in[i] != 0 && curr.size() % 2 == 0) {
				int[] temp = curr.pollLast();
				System.out.print(temp[1] + " ");
				curr.add(temp);
			} else {
				System.out.print(0 + " ");
			}
			for (int[] j : b[i])
				curr.remove(j);
		}
		sc.close();
	}

	static class cmpSL implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[0] - o2[0];
		}
	}
}
