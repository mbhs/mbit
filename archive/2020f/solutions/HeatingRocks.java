import java.util.*;
import java.io.*;

// By Ayush Varshney
public class HeatingRocks {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), x = sc.nextInt();
		long max = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int a = Math.max(0, x - sc.nextInt());
			max = Math.max(max, a);
			sum += a;
		}
		if (max * 2 >= sum) {
			System.out.println(max);
		} else {
			if (sum % 2 == 0) {
				System.out.println(sum / 2);
			} else {
				System.out.println(sum / 2 + 1);
			}
		}
		sc.close();
	}

}