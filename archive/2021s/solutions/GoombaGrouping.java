import java.util.*;
import java.io.*;

public class GoombaGrouping {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		long inf = (long) 1e18;
		int t = sc.nextInt();
		while (t-- > 0) {
			long n = sc.nextLong();
			long k = sc.nextLong();
			if (n <= 4) {
				System.out.println(-1);
				continue;
			}
			System.out.print(inf + " " + inf + " ");
			n -= 2;
			long sz = 2 * inf - k;
			if (n % 2 == 0) {
				System.out.print("1 ");
				n--;
				sz--;
			}
			for (int i = 0; i < n; i++)
				if (i < (sz % n))
					System.out.print(sz / n + 1 + " ");
				else
					System.out.print(sz / n + " ");
			System.out.println();
		}
		sc.close();
	}

}