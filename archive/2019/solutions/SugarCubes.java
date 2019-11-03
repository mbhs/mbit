import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SugarCubes {

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine()), ret = 0;
		for (int i=1; i<=n; i++)
			for (int j=i; j<=n; j++)
				for (int k=j; k<=n; k++)
					if (i * j * k == n)
						ret++;
		
		System.out.println(ret);

	}

}