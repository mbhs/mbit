import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Banquet {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		long out = 0, pos = 0;
		for (int i = 0; i < n; i++) {
			a[i]= sc.nextInt();
			for (int j = 0; j < a[i]; j++) {
				out += Math.abs(i - pos);
				pos += 1;
			}
		}
		System.out.println(out);
		sc.close();
	}

}