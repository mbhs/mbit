import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Genotypes {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		String s1 = br.readLine(), s2 = br.readLine();
		
		int ret = 1;
		for (int i=0; i<n; i++)
			if (s1.charAt(i) != s2.charAt(i))
				ret *= 2;
		
		System.out.println(ret);

	}

}