import java.util.*;
import java.io.*;

// By Ayush Varshney
public class IceCream {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double cntP = 0, cntB = 0, sumPX = 0, sumPY = 0, sumBX = 0, sumBY = 0;
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) == ('p')) {
                    cntP++;
                    sumPY += i + 1;
                    sumPX += j + 1;
                } else if (s.charAt(j) == ('b')) {
                    cntB++;
                    sumBY += i + 1;
                    sumBX += j + 1;
                }
            }
        }
        double PX = sumPX / cntP, PY = sumPY / cntP, BX = sumBX / cntB, BY = sumBY / cntB;
        double deg = Math.toDegrees(Math.atan(Math.abs(PY - BY) / Math.abs(PX - BX)));
        if (Math.abs(deg - 90) < Math.abs(deg)) {
            if (PY < BY) {
                System.out.println(0);
            } else {
                System.out.println(180);
            }
        } else {
            if (PX > BX) {
                System.out.println(90);
            } else {
                System.out.println(270);
            }
        }
        sc.close();
    }
	
}