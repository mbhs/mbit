
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class ContradictoryCanele {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int maxY = sc.nextInt(), maxX = sc.nextInt(), subY = sc.nextInt(), subX = sc.nextInt();
        if (maxX % subX == 0 && maxY % subY == 0) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            long[][] sub = new long[subY][subX];
            long temp = 0;
            for (int i = 0; i < subY; i++)
                for (int j = 0; j < subX; j++)
                    sub[i][j] = -(++temp);
            --temp;
            sub[subY - 1][subX - 1] = (temp * (temp + 1)) / 2;
            for (int i = 0; i < maxY; i++) {
                for (int j = 0; j < maxX; j++) {
                    System.out.print(sub[i % subY][j % subX] + " ");
                }
                System.out.println();
            }
        }
        sc.close();
    }
	
}
