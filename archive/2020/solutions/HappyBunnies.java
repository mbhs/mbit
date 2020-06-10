import java.util.*;
import java.io.*;

// By Ayush Varshney
public class HappyBunnies {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);		
		int a = sc.nextInt(), b = sc.nextInt();
		long sum = 0;
	    for(int i = a; i <= b; i++){
	        sum += getNumVal(i);
	    }
	    System.out.println(sum);
		sc.close();
	}
	
	static int getNumVal(int val){
	    int tot = val;
	    while(val > 0){
	        int currDig = val % 10;
	        if(currDig == 7){
	            return 0;
	        }
	        val /= 10;
	        tot += currDig;
	    }
	    return tot;
	}

}