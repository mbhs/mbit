import java.util.*;
import java.io.*;

// By Ayush Varshney
public class PiratingParrots {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		int x = sc.nextInt(), y = sc.nextInt();
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == 'U') {
				y -= 1;
			} else if (s.charAt(i) == 'D') {
				y += 1;
			} else if (s.charAt(i) == 'R') {
				x -= 1;
			} else {
				x += 1;
			}
		}
		System.out.println(Math.abs(x) + Math.abs(y));
		sc.close();
	}

}