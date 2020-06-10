import java.util.*;
import java.io.*;

// By Ayush Varshney
public class EggInterception {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt()-1;
        Long[] a = new Long[n];
        HashMap<Long, Integer> b = new HashMap<>();
        for(int i = 0; i < n; i++) {
        	a[i] = sc.nextLong()-1;
        	b.put(a[i], i);
        }
        Arrays.sort(a);
        long out = 0, prev = k;
        for(int i = 0; i < n; i++) {
        	out += Math.abs(prev - b.get(a[i]));
        	prev = b.get(a[i]);
        }
        System.out.println(out);
        sc.close();
    }

}