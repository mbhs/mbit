import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Weights {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Long[] in = new Long[n];
		for (int i = 0; i < n; i++) {
			in[i] = sc.nextLong();
		}
		Arrays.sort(in);
		for(int i = 1; i < n; i++) {
			in[i] += in[i-1];
		}
		double out = 0;
		for(int i = 0; i < n-1; i++) {
			out = Math.max(Math.abs((double)in[i]/(i+1)-(double)(in[in.length-1]-in[i])/(n-i-1)), out);
		}		
		System.out.println(out);//String.format("%.16f", out));
		sc.close();
	}

}