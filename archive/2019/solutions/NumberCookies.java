
import java.util.*;
import java.io.*;
import java.math.BigInteger;

// By Ayush Varshney
public class NumberCookies {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] operC = new int[4]; // *, +, -, |
        int[] numC = new int[10]; // 0, 1, ..., 9
        int count = 0, stInd = 0, stInd0 = 0, stInd1 = 0, stInd2 = 0;
        for (int i = 0; i < n; i++) {
        Character c = sc.next().charAt(0);
        if (Character.isDigit(c)) {
            numC[Integer.parseInt(c.toString())]++;
            count++;
        } else {
            if (c == '*') {
                operC[0]++;
                } else if (c == '+') {
                    operC[1]++;
                } else {
                    operC[2]++;
                }
            }
        }
        BigInteger[] in = new BigInteger[count];
        BigInteger out = BigInteger.ZERO;
        for (int i = 0; i < 10; i++) {
            if (numC[i] > 0) {
                stInd0 += numC[i];
                Arrays.fill(in, stInd, stInd0, BigInteger.valueOf(i));
                stInd = stInd0;
            }
        }
        operC[3] = n - 2 * operC[0] - 2 * operC[1] - 2 * operC[2] - 1;
        
        // get rid of -
        while (operC[2] > 0) {
            out = out.subtract(in[stInd1]);
            operC[2]--;
            stInd1++;
        }
        
        // get rid of +
        stInd2 = stInd1 + operC[1];
        while (stInd1 < stInd2) {
            out = out.add(in[stInd1]);
            stInd1++;
        }
        
        // get rid of |
        if (operC[0] == 0) {
        
            // without *
            while (operC[3] > 0) {
                in[stInd2 + 1] = new BigInteger(in[stInd2 + 1].toString() + in[stInd2].toString());
                stInd2++;
                operC[3]--;
            }
            out = out.add(in[count - 1]);
        
        } else {
        
            // with *
            while (stInd2 < count - 2 * (operC[0] + 1)) {
                in[stInd2 + operC[0] + 1] = new BigInteger(in[stInd2 + operC[0] + 1].toString() + in[stInd2].toString());
                stInd2++;
            }
            int temp = (operC[0] + 1) * 2 - 1;
            for (int i = count - 1; i >= count - operC[0] - 1; i--) {
                if (i - temp >= stInd2) {
                    in[i] = new BigInteger(in[i].toString() + in[i - temp].toString());
                }
                temp -= 2;
            }
            stInd2 = count - operC[0] - 1;
            while (stInd2 != count - 1) {
                in[stInd2 + 1] = in[stInd2].multiply(in[stInd2 + 1]);
                stInd2++;
            }
            out = out.add(in[count - 1]);
        
        }
        
        System.out.println(out);
        sc.close();
    }
    
}