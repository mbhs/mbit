
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class FrostingPatterns {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        String s = sc.next(), pat = s;
        for (int len = n/2; len > 1; len--) {
            String temp = s.substring(0, len);
            boolean works = true;
            int i = len * 2;
            for (; i <= n; i += len) {
                works &= temp.equals(s.substring(i - len, i));
                if (!works)
                    break;
            }
            if (i != 2 * n && works) {
                i -= len;
                works &= temp.substring(0, s.substring(i).length()).equals(s.substring(i));
            }
            if (works){
                pat = temp;
                break;
            }
        }
        String out = pat.substring(n % pat.length());
        while (m - out.length() > 0) {
            out = out + pat;
        }
        System.out.println(out.substring(0, m));
        sc.close();
    }
    
}