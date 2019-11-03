
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class HotCake {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] in = new int[n];
        for(int i = 0; i < n; i++){
            in[i] = sc.nextInt();
        }
        ArrayList<Integer> pat = new ArrayList<Integer>();
        HashSet<Integer> vis = new HashSet<Integer>();
        int temp = 1;
        for (int i = 0; i < n; i++) {
            int x = in[temp - 1];
            if (vis.contains(x))
                break;
            pat.add(x);
            temp = x;
            vis.add(temp);
        }
        System.out.println(pat.get((k - 1) % pat.size()));
        sc.close();
    }

}
