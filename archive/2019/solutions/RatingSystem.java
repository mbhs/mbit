
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class RatingSystem {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong(), b = sc.nextLong();
        String in = sc.next();
        if(in.toLowerCase().equals("w")) {
            a += b*10/100;
        } else {
            a -= a*10/100;	
        }
        System.out.println(a);
        sc.close();
    }
	
}