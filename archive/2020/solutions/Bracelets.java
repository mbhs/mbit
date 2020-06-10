import java.util.*;
import java.io.*;

// By Ayush Varshney
public class Bracelets  {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] aa = new int[n];
        for(int i = 0; i < n; i++) {
        	int x = sc.nextInt()-1;
        	a[x] = i;
        	aa[i] = x;
        }
        int[] b = new int[n];
        int[] bb = new int[n];
        for(int i = 0; i < n; i++) {
        	int x = sc.nextInt()-1;
        	b[x] = i;
        	bb[i] = x;
        }
        int[] c = new int[n];
        for(int i = 0; i < n; i++) {
        	c[i] = a[i];
        	c[i] -= b[i];
        	if(c[i] < 0) {
        		c[i] += n;
        	}
        }
        int[] cnt = new int[n];
        int max = 0;
        int maxdex = 0;
        for(int i = 0; i < n; i++) {
        	cnt[c[i]]++;
        	if(cnt[c[i]] > max) {
        		maxdex = c[i];
        		max = cnt[c[i]];
        	}
        }
        int tot = 0;
        for(int i = 0; i < n; i++) {
        	if(bb[i] == aa[(i+maxdex)%n]) {
        		tot++;
        	}
        }
        System.out.println(tot);
        sc.close();
    }

}