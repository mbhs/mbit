import java.util.*;
import java.io.*;

// By Ayush Varshney
public class MusicalBowings {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), up = 0, revPos = n-1;
		String t = "", rev = "";
		String[] out = new String[n];
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			if (s.equals("B") && revPos == n-1) 
				continue;
			if(revPos == n-1) {
				revPos = i-1;
				rev = s;
			}
			if (s.equals("U")) {
				up++;
				t = "U";
				out[i] = "U";
			} else if (t.equals("D") && s.equals("B")) {
				up++;
				t = "U";
				out[i] = "U";
			} else {
				t = "D";
				out[i] = "D";
			}
		}
		t = rev;
		for(int i = revPos; i > -1; i--) {
			if (t.equals("D")) {
				up++;
				t = "U";
				out[i] = "U";
			} else {
				t = "D";
				out[i] = "D";
			}
		}
		for(String str : out) {
			System.out.print(str + " ");
		}
		sc.close();
	}

}