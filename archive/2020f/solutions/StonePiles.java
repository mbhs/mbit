import java.util.*;
import java.io.*;
import java.util.StringTokenizer;

public class StoneCircle {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		OutputWriter out = new OutputWriter(System.out);
		
		int n = sc.nextInt(), m = sc.nextInt();
		int[] arr = new int[n];
		int[] arr2 = new int[n];
		int k = sc.nextInt();
		int notm = 0, two = 0;
		for (int j = k - 1; j > -1; j--) {
			int o = sc.nextInt();
			arr[j] = o;
			if (o != m)
				notm++;
			if (o == 2)
				two++;
		}
		int prev = n - k, ind = k, old = k;
		for (int i = 1; i < m; i++) {
			k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				int o = sc.nextInt();
				arr2[ind] = i + 1;
				arr[ind] = o;
				ind++;
				if (o != m)
					notm++;
				if (o == 2)
					two++;
			}
		}
		out.print(prev + n + notm + two + "\n");
		for (int i = old; i < n; i++) {
			out.print(arr2[i] + " 1" + "\n");
		}
		for (int i = n - 1; i > -1; i--) {
			int o = arr[i];
			if (o == m) {
				out.print("1 " + m + "\n");
				arr[i] = -1;
			} else {
				out.print("1 2" + "\n");
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i] == -1)
				continue;
			int o = arr[i];
			if (o == 2) {
				out.print("2 " + m + "\n");
			} else {
				out.print("2 " + o + "\n");
				arr[i] = -1;
			}
		}
		for (int i = n - 1; i > -1; i--) {
			if (arr[i] == -1)
				continue;
			out.print(m + " 2" + "\n");
		}
		out.close();
	}

}

class Scanner{
  public BufferedReader reader;
  public StringTokenizer st;

  public Scanner(InputStream stream){
    reader = new BufferedReader(new InputStreamReader(stream));
    st = null;
  }

  public String next(){
    while(st == null || !st.hasMoreTokens()){
      try{
        String line  = reader.readLine();
        if(line == null) return null;
        st =  new StringTokenizer(line);
      }catch (Exception e){
        throw (new RuntimeException());
      }
    }
    return st.nextToken();
  }

  public int nextInt(){
    return Integer.parseInt(next());
  }
  public long nextLong(){
    return Long.parseLong(next());
  }
  public double nextDouble(){
    return Double.parseDouble(next());
  }
}

class OutputWriter{
  BufferedWriter writer;

  public OutputWriter(OutputStream stream){
    writer = new BufferedWriter(new OutputStreamWriter(stream));
  }

  public void print(int i) throws IOException {
    writer.write(i);
  }

  public void print(String s) throws IOException {
    writer.write(s);
  }

  public void print(char []c) throws IOException {
    writer.write(c);
  }
  public  void close() throws IOException {
    writer.close();
  }

}