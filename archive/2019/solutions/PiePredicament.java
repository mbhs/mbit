import java.util.*;
import java.io.*;

// By Ayush Varshney
public class PiePredicament {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), c = sc.nextInt();
        int[] in = new int[n];
        for(int i = 0; i < n; i++){
            in[i] = sc.nextInt();
        }
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int l = 0, r = 1, min = Integer.MAX_VALUE, bestL = l, bestR = r;
        hm.put(in[0], 1);
        while (r != n) {
            if (hm.containsKey(in[r])) {
                hm.put(in[r], hm.get(in[r]) + 1);
                while (hm.get(in[l]) > 1) {
                    hm.put(in[l], hm.get(in[l]) - 1);
                    l++;
                }
            } else {
                hm.put(in[r], 1);
            }
            r++;
            if (hm.size() == c) {
                if (r - l < min && r - l != bestR - bestL) {
                    min = r - l;
                    bestR = r;
                    bestL = l;
                }
            }
        }
        System.out.println((bestL) + " " + (n - bestR));
        sc.close();
    }
	
}