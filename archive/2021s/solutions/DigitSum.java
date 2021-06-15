import java.util.*;
import java.io.*;

public class DigitSum {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		if (n == 0) {
			if (m == 1) {
				System.out.println("0");
			} else {
				System.out.println("-1");
			}
		} else {
			String out = "";
			if (n <= 9 * m) {
				while (n > 9) {
					out += "9";
					n -= 9;
					m--;
				}
				out += Integer.toString(n);
				m--;
				while (m > 0) {
					out += "0";
					m--;
				}
			}
			if(out.equals("")) {
				out = "-1";
			}
			System.out.println(out);
		}
		sc.close();
	}

}