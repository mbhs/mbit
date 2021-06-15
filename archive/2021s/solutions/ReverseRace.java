import java.util.*;
import java.io.*;

public class ReverseRace {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		ArrayList<String> in = new ArrayList<>();
		Collections.addAll(in, s.split(" "));
		boolean[] caps = new boolean[in.size()];
		for (int i = 0; i < in.size(); i++) {
			caps[i] = (int) in.get(i).charAt(0) < 97;
		}
		String out = "";
		for (int i = in.size() - 1; i > -1; i--) {
			char[] temp = in.get(i).toLowerCase().toCharArray();
			String temp2 = "";
			for (int j = temp.length - 1; j > -1; j--) {
				temp2 += temp[j];
			}
			in.set(i, temp2);
			if (caps[i]) {
				out += in.get(i).substring(0, 1).toUpperCase() + in.get(i).substring(1);
			} else {
				out += in.get(i);
			}
			out += " ";
		}
		System.out.println(out);
		sc.close();
	}

}