import java.util.*;
import java.io.*;

// By Ayush Varshney
public class RagingRhinos {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<int[]> line = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int s = sc.nextInt();
			int d = sc.nextInt();
			while (line.size() != 0 && s > 0 && line.get(line.size() - 1)[1] == 1 && d == 0) {
				if (line.get(line.size() - 1)[0] <= s) {
					s -= line.get(line.size() - 1)[0];
					line.remove(line.size() - 1);
				} else {
					line.get(line.size() - 1)[0] -= s;
					s = 0;
				}
			}
			if (s > 0)
				line.add(new int[] { s, d });
		}
		System.out.println(line.size());
		for (int[] i : line) {
			System.out.println(i[0] + " " + i[1]);
		}
		sc.close();
	}

}