import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Calendars {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
		}
		int[] pos = new int[n+1];
		for (int i = 0; i < n; i++) {
			pos[a[i]] = i;
		}
		long left = 0, right = 0, out = 0;
		int[] change = new int[n+1];
		for (int i = 0; i < n; i++) {
			if (i <= pos[b[i]]) {
				left++;
				change[i + n - pos[b[i]]]++;
			} else {
				right++;
				change[i - pos[b[i]]]++;
			}
			out += Math.abs(i - pos[b[i]]);
		}
		long cur = out;
		for (int i = 1; i < n; i++) {
			cur += left - right + n - 2 * (pos[b[i - 1]] + 1);
			left += change[i] - 1;
			right -= change[i] - 1;
			out = Math.min(out, cur);
		}
		System.out.println(out);
		sc.close();
	}

}