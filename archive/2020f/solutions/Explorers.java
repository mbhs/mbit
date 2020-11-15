import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Explorers {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		ArrayList<int[]> zheng = new ArrayList<>();
		ArrayList<int[]> yang = new ArrayList<>();
		for (int i = n - 1; i > -1; i--) {
			if (Math.abs(n - i - 1) % 2 == 1) {
				for (int j = 0; j < m; j++) {
					zheng.add(new int[] { i, j });
				}
			} else {
				for (int j = m - 1; j > -1; j--) {
					zheng.add(new int[] { i, j });
				}
			}
		}
		for (int j = 0; j < m; j++) {
			if (Math.abs(j + 1) % 2 == 1) {
				for (int i = 0; i < n; i++) {
					yang.add(new int[] { i, j });
				}
			} else {
				for (int i = n - 1; i > -1; i--) {
					yang.add(new int[] { i, j });
				}
			}
		}
		int cnt = 0;
		ArrayList<Integer> out = new ArrayList<>();
		for (int i = 0; i < n * m; i++) {
			if (zheng.get(i)[0] == yang.get(i)[0] && zheng.get(i)[1] == yang.get(i)[1]) {
				out.add(i + 1);
				cnt++;
			}
		}
		System.out.println(cnt);
		for (int i : out) {
			System.out.print(i + " ");
		}
		sc.close();
	}

}