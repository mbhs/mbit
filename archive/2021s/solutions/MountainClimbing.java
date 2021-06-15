import java.util.*;
import java.io.*;

public class MountainClimbing {

	public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int out = 0, prev = 0;
        int n = sc.nextInt();
        for(int i = 0; i < n; i++) {
        	int curr = sc.nextInt();
        	out++;
        	out += Math.abs(prev-curr);
        	prev = curr;
        }
        out+=prev;
        System.out.println(out);
        sc.close();
	}

}