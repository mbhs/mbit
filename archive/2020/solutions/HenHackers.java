import java.util.*;
import java.io.*;

// By Ayush Varshney
public class HenHackers {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws IOException {
		ArrayList<Integer> all = new ArrayList<>();
		for (int i = 48; i <= 122; i++) {
			if (q(i))
				all.add(i);
			if (i == 57)
				i = 64;
			else if (i == 90)
				i = 96;
		}
		Collections.sort(all, new cmpHH());
		for (int i : all)
			System.out.print((char) i);
		sc.close();
	}

	static boolean q(int i) {
		System.out.println((char) i);
		String ret = sc.next();
		if(ret.equals("C"))
			System.exit(0);
		return ret.equals("Y");
	}

	static class cmpHH implements Comparator<Integer> {
		@Override
		public int compare(Integer o1, Integer o2) {
			if (q(o1, o2))
				return -1;
			return 1;
		}

		static boolean q(int i, int j) {
			System.out.println(((char) i) + "" + ((char) j));
			String ret = sc.next();
			if(ret.equals("C"))
				System.exit(0);
			return ret.equals("Y");
		}
	}

}
