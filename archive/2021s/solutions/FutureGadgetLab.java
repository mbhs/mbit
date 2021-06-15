import java.util.*;
import java.io.*;

public class FutureGadgetLab {

	static ArrayList<Integer>[] adj;
	static Stack<double[]> stack;
	static double[] prob;
	static int g, res;
	static double ans, sum;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), j = sc.nextInt(), k = sc.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			adj[u - 1].add(v - 1);
		}
		prob = new double[n];
		g = 0;
		stack = new Stack<>();
		stack.add(new double[] { 0, 1, 0 });
		int i = 0;
		while (i < stack.size()) {
			dfs(i);
			i++;
		}
		res = (int) pow(j, k);
		sum = 0;
		for (double d : prob)
			sum += d;
		ans = 0;
		stack = new Stack<>();
		stack.add(new double[] { 0, 0 });
		i = 0;
		while (i < stack.size()) {
			dfs2(i);
			i++;
		}
		System.out.println(ans);
		sc.close();
	}

	static void dfs(int i) {
		double[] temp = stack.get(i);
		int u = (int) temp[0];
		double x = temp[1];
		int d = (int) temp[2];
		prob[u] = x;
		for (int v : adj[u])
			stack.add(new double[] { v, x / adj[u].size(), d + 1 });
		if (adj[u].size() == 0)
			g = gcd(g, d + 1);
	}

	static void dfs2(int i) {
		double[] temp = stack.get(i);
		int u = (int) temp[0];
		int d = (int) temp[1];
		if (d % g == res)
			ans += prob[u] * (double) g / (double) sum * d;
		for (int v : adj[u])
			stack.add(new double[] { v, d + 1 });
	}

	static long pow(long a, long b) {
		if (b == 0)
			return 1L;
		long val = pow(a, b / 2);
		if (b % 2 == 0)
			return val * val % g;
		else
			return val * val % g * a % g;
	}

	static int gcd(int a, int b) {
		if (a > b)
			return gcd(b, a);
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

}