import java.util.*;
import java.io.*;

// By Ayush Varshney
public class DoubleTrouble {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int n = s.length();
		boolean[] del = new boolean[n+2];
		s = '0' + s + '0';
		for (int i = 1; i < n; i++) {
			del[i] = (s.charAt(i) == s.charAt(i + 1) && s.charAt(i - 1) != s.charAt(i) && s.charAt(i + 2) != s.charAt(i));
		}
		for (int i = 1; i < n + 1; i++) {
			if (!del[i]) {
				System.out.print(s.charAt(i));
			}
		}
		sc.close();
	}
}