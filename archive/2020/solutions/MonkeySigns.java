import java.util.*;
import java.io.*;

// By Ayush Varshney
public class MonkeySigns {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine().toLowerCase();
		int[] cnt = new int[26];
		for (int i = 0; i < s.length(); i++)
			if ((int) s.charAt(i) > 96)
				cnt[(int) s.charAt(i) - 97]++;
		int out = cnt[(int) 'm' - 97];
		cnt[(int) 'm' - 97] = 0;
		int max = 0;
		for (int i = 0; i < 26; i++)
			max = Math.max(max, cnt[i]);
		System.out.println(out + max);
		sc.close();
	}

}