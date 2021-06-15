import java.util.*;
import java.io.*;

public class ImmortalityPotion {

	static ArrayList<String> ans;
	static char[] chem;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int[] want = new int[3];
		want[0] = sc.nextInt();
		want[1] = sc.nextInt();
		want[2] = sc.nextInt();
		double d = want[0] + want[1] + want[2];
		chem = new char[] { 'a', 'b', 'c' };
		ans = new ArrayList<>();
		if (want[0] >= want[1] && want[0] >= want[2]) {
			bsearch(1, want[1] / d * 2, 0);
			bsearch(2, want[2] / d * 2, 0);
		} else if (want[1] >= want[0] && want[1] >= want[2]) {
			bsearch(0, want[0] / d * 2, 1);
			bsearch(2, want[2] / d * 2, 1);
		} else {
			bsearch(0, want[0] / d * 2, 2);
			bsearch(1, want[1] / d * 2, 2);
		}
		finish(3);
		System.out.println(ans.size());
		for(String s : ans) {
			System.out.println(s);
		}
		sc.close();
	}

	static void fill(int cup, int a) {
		ans.add("F " + cup + " " + chem[a]);
	}

	static void empty(int cup) {
		ans.add("E " + cup);
	}

	static void pour(int cup1, int cup2) {
		ans.add("P " + cup1 + " " + cup2);
	}

	static void finish(int cup) {
		ans.add("! " + cup);
	}

	static void bsearch(int c1, double amt, int c2) {
		int[] a = new int[32];
		double x = amt;
		for (int i = 0; i < 32; i++) {
			x *= 2;
			if (x > 1) {
				a[i] = 1;
				x -= 1;
			} else {
				a[i] = 0;
			}
		}
		empty(1);
		empty(2);
		fill(2, c1);
		for (int i = 31; i > -1; i--) {
			pour(2, 1);
			empty(1);
			if (a[i] == 1) {
				fill(1, c1);
			} else {
				fill(1, c2);
			}
			pour(1, 2);
		}
		pour(2, 1);
		pour(1, 3);
	}

}