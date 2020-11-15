import java.util.*;
import java.io.*;

// By Ayush Varshney
public class ApplePie {

	public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt(), m = sc.nextInt(), n = sc.nextInt();
        if(k*10<=n) {
        	System.out.println(0);
        }else {
        	System.out.println((k * 10 - n + m - 1) / m);
        }
        sc.close();
	}

}