import java.util.*;
import java.io.*;

// By Ayush Varshney
public class SnakeMoves {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int out = 0;
		int w = sc.nextInt(), h = sc.nextInt(), x = sc.nextInt() - 1, y = sc.nextInt() - 1, n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int nextx = sc.nextInt() - 1;
			int nexty = sc.nextInt() - 1;
			if (x == nextx || y == nexty || (x + y == nextx + nexty) || (x - y == nextx - nexty)) {
				out--;
			}
			out += 2;
			x = nextx;
			y = nexty;
		}
		System.out.println(out);
		sc.close();
	}

}