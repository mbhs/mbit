
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class CoffeeSwapping {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), count = 0;
        Integer[] in = new Integer[2*n];
        for(int i = 0; i < n*2; i++){
            in[i] = sc.nextInt();
        }
        Integer[] copy = in.clone();
        Arrays.sort(copy);
        HashMap<Integer, Point> hm = new HashMap<Integer, Point>();
        for (int i = 0; i < 2 * n; i++) {
            hm.put(copy[i], new Point(copy[2 * n - i - 1], 0));
        }
        for (int i = 0; i < 2 * n; i++) {
            hm.get(hm.get(in[i]).a).b = i;
        }
        for (int i = 0; i < 2 * n; i += 2) {
            if (!hm.get(in[i]).a.equals(in[i + 1])) {
                hm.get(hm.get(in[i + 1]).a).b = hm.get(in[i]).b;
                int temp = in[i + 1];
                in[i + 1] = in[hm.get(in[i]).b];
                in[hm.get(in[i]).b] = temp;
                hm.get(in[i]).b = i + 1;
                count++;
            }
        }
        System.out.println(count);
        sc.close();
    }
        
    static class Point{
        Integer a;
        Integer b;
        
        Point(Integer a, Integer b) {
            this.a = a;
            this.b = b;
        }
    }
	
}
