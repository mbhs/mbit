import java.util.*;
import java.io.*;

// By Ayush Varshney
public class IceCreamTruck {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int n = sc.nextInt();
		if (5 * a <= b) {
			System.out.println(a * n);
		} else {
			System.out.println(a * (n % 5) + b * (n / 5));
		}
		sc.close();
	}

}