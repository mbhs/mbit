
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class MountainMileage {
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), A = sc.nextInt(), B = sc.nextInt();
        Integer[] in = new Integer[n];
        for(int i = 0; i < n; i++){
            in[i] = sc.nextInt();
        }
        double lo, hi;
        lo = hi = in[0];
        for (int i : in) {
            lo = Math.min(i, lo);
            hi = Math.max(i, hi);
        }
        while ((hi - lo) > 0.00000001) {
            double mi1;
            double mi2;
            mi1 = lo + ((hi - lo) / 3);
            mi2 = hi - ((hi - lo) / 3);
            double s1 = 0;
            for (int i : in) {
                s1 += Math.max(A * (mi1 - i), B * (i - mi1));
            }
            double s2 = 0;
            for (int i : in) {
                s2 += Math.max(A * (mi2 - i), B * (i - mi2));
            }
            if (s1 < s2)
                hi = mi2;
            else
                lo = mi1;
        }
        long l = (long) ((hi + lo) / 2);
        long s3 = 0;
        for (int i : in) {
            s3 += Math.max(A * (l - i), B * (i - l));
        }
        l++;
        long s4 = 0;
        for (int i : in) {
            s4 += Math.max(A * (l - i), B * (i - l));
        }
        System.out.println(Math.min(s3, s4));
        sc.close();
    }

}
