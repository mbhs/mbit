import java.util.*;
import java.io.*;

// By Ayush Varshney
public class NumberGame {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.next() + "000", out = "";
		int i = 0;
		while (i != s.length()) {
			if (s.charAt(i) == '0') {
				out = out.concat("0");
				i++;
			} else if (s.charAt(i) == '1') {
				if (s.charAt(i + 1) == '6') {
					out = out.concat("4");
					i += 2;
				} else {
					out = out.concat("1");
					i++;
				}
			} else if (s.charAt(i) == '2') {
				if (s.charAt(i + 1) == '5') {
					out = out.concat("5");
					i += 2;
				} else if (s.charAt(i + 1) == '7') {
					out = out.concat("3");
					i += 2;
				} else if (s.charAt(i + 1) == '1' && s.charAt(i + 2) == '6') {
					out = out.concat("6");
					i += 3;
				} else {
					out = "-1000";
					break;
				}
			} else if (s.charAt(i) == '3') {
				if (s.charAt(i + 1) == '6') {
					out = out.concat("6");
					i += 2;
				} else if (s.charAt(i + 1) == '4' && s.charAt(i + 2) == '3') {
					out = out.concat("7");
					i += 3;
				} else {
					out = "-1000";
					break;
				}
			} else if (s.charAt(i) == '4') {
				out = out.concat("2");
				i++;
			} else if (s.charAt(i) == '5') {
				if (s.charAt(i + 1) == '1' && s.charAt(i + 2) == '2') {
					out = out.concat("8");
					i += 3;
				} else {
					out = "-1000";
					break;
				}
			} else if (s.charAt(i) == '6') {
				if (s.charAt(i + 1) == '4') {
					out = out.concat("8");
					i += 2;
				} else {
					out = "-1000";
					break;
				}
			} else if (s.charAt(i) == '7') {
				if (s.charAt(i + 1) == '2' && s.charAt(i + 2) == '9') {
					out = out.concat("9");
					i += 3;
				} else {
					out = "-1000";
					break;
				}
			} else if (s.charAt(i) == '8') {
				out = out.concat("2");
				i++;
			} else {
				out = out.concat("3");
				i++;
			}
		}
		System.out.println(out.substring(0, out.length() - 3));
		sc.close();
	}

}