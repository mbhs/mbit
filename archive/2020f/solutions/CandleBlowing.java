import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Candles {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt(), b = sc.nextInt();
		String s = sc.next();
		int[] dr = new int[] { -1, 0, 1, 0 };
		int[] dc = new int[] { 0, 1, 0, -1 };
		boolean[][] vis = new boolean[n + 1][m + 1];
		ArrayList<int[]>[] lit = new ArrayList[4];
		for (int i = 0; i < 4; i++) {
			lit[i] = new ArrayList<>();
		}
		for (int i = 0; i < k; i++) {
			int r = sc.nextInt(), c = sc.nextInt();
			r--;
			c--;
			vis[r][c] = true;
			for (int j = 0; j < 4; j++) {
				lit[j].add(new int[] { r, c });
			}
		}

		int ret = k;
		for (char ch : s.toCharArray()) {
			int d = ch == 'N' ? 0 : ch == 'E' ? 1 : ch == 'S' ? 2 : 3;
			ArrayList<int[]> add = new ArrayList<>();
			for (int[] i : lit[d]) {
				int nr = i[0] + dr[d], nc = i[1] + dc[d];
				if (0 <= nr && nr < n && 0 <= nc && nc < m && !vis[nr][nc]) {
					ret++;
					vis[nr][nc] = true;
					add.add(new int[] { nr, nc });
				}
			}
			lit[d].clear();
			for (int j = 0; j < 4; j++)
				lit[j].addAll(add);
			System.out.println(ret);
		}
		sc.close();
	}

}