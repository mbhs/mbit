
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class BakingPan {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long minX = Long.MAX_VALUE, maxX = Long.MIN_VALUE, minY = Long.MAX_VALUE, maxY = Long.MIN_VALUE;
        while (n-- > 0) {
            int x = sc.nextInt(), y = sc.nextInt(), r = sc.nextInt();
            minX = Math.min(minX, x-r);
            maxX = Math.max(maxX, x+r);
            minY = Math.min(minY, y-r);
            maxY = Math.max(maxY, y+r);
        }
        long area = (maxX-minX)*(maxY-minY);
        System.out.println(area);
        sc.close();
    }
    
}