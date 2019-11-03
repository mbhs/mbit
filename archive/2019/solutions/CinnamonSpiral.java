import java.util.Scanner;

public class CinnamonSpiral {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		long x = sc.nextLong(), y = sc.nextLong();
		long layer = Math.max(Math.abs(x), Math.abs(y));
		long ret = 4 * layer * (layer - 1);
		if (x == layer)
			ret += layer + y;
		else if (y == layer)
			ret += 3 * layer - x;
		else if (x == -layer)
			ret += 5 * layer - y;
		else
			ret += 7 * layer + x;
		
		System.out.println(ret);
		
		sc.close();

	}

}