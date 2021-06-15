import java.util.*;
import java.io.*;

public class PokemonPermutation {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String in = sc.next();
		int[] freq = new int[26];
		for (int i = 0; i < in.length(); i++) {
			freq[in.charAt(i) - 'a']++;
		}
		int gcd = 0;
		for (int i = 0; i < 26; i++) {
			if (gcd == 0 && freq[i] != 0) {
				gcd = freq[i];
			} else if (freq[i] != 0) {
				gcd = gcd(gcd, freq[i]);
			}
		}
		for (int i = 0; i < 26; i++) {
			freq[i] /= gcd;
		}
		if (gcd == 1) {
			System.out.println("IMPOSSIBLE");
		} else {
			String out = "";
			for (int i = 0; i < 26; i++) {
				while (freq[i] != 0) {
					freq[i]--;
					out += (char) (i + 'a');
				}
			}
			String out2 = "";
			while (gcd != 0) {
				out2 += out;
				gcd--;
			}
			System.out.println(out2);
		}
		sc.close();
	}

	public static int gcd(int n1, int n2) {
		if (n2 == 0) {
			return n1;
		}
		return gcd(n2, n1 % n2);
	}

}