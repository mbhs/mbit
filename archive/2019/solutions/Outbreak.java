import java.io.*;
import java.util.*;

public class Outbreak {
	
	final static int MOD = 1000000007;
	
	static long[] o = new long[400001], ret = new long[100000];
	static long[][] pre = new long[400001][2];

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), q = sc.nextInt();
		for (int i=0; i<n; i++)
			o[i] = sc.nextInt();
		
		pre[0][0] = o[0];
		pre[0][1] = 1;
		for (int i=1; i<n; i++) {
			pre[i][0] = pre[i-1][0] * o[i] % MOD;
			pre[i][1] = pre[i-1][1] * pow(o[i], i) % MOD;
		}
		
		int cnt = 0;
		Segtree tree = new Segtree();
		tree.init(n, o);
		for (int i=0; i<q; i++) {
			int t = sc.nextInt(), l = sc.nextInt() - 1, r = sc.nextInt() - 1;
			if (t == 1)
				tree.update(l, r, sc.nextInt());
			else
				ret[cnt++] = tree.query(l, r);
		}
		
		for (int i=0; i<cnt; i++)
			System.out.println(ret[i]);
		
		sc.close();

	}
	
	static long pow(long a, long b) {
	    long ret = 1;
	    while (b > 0) {
	        if (b % 2 == 1)
	            ret = (ret * a) % MOD;
	        a = (a * a) % MOD;
	        b >>= 1;
	    }
	    return ret;
	}
	
	static class Pair {
		long f, s;
		
		Pair(long f, long s) {
			this.f = f;
			this.s = s;
		}
	}
	
	static class Segtree {
	  int n;
	  ArrayList<Long> tree;
	  ArrayList<Pair> stats, lazy;

	  void init(int s, long[] arr) {
	    n = s;
	    tree = new ArrayList<Long>();
	    lazy = new ArrayList<Pair>();
	    stats = new ArrayList<Pair>();
	    for (int i=0; i<4*s; i++) {
	    	tree.add(0L);
	    	lazy.add(new Pair(0, 0));
	    	stats.add(new Pair(0, 0));
	    }
	    init(0, 0, n - 1, arr);
	  }

	  long init(int i, int l, int r, long[] arr) {
	    if (l == r) {
	      stats.get(i).f = arr[l];
	      stats.get(i).s = 1;
	      tree.set(i, arr[l]);
	      return arr[l];
	    }

	    int mid = (l + r) / 2;
	    long a = init(2 * i + 1, l, mid, arr),
	          b = init(2 * i + 2, mid + 1, r, arr);
	    
	    long x = (l > 0 ? pre[l - 1][0] : 1);
	    long y = (l > 0 ? pre[l - 1][1] : 1);
	    stats.get(i).f = (pre[r][0] * pow(x, MOD - 2)) % MOD; /* range mul */
	    stats.get(i).s = (pre[r][1] * pow(y, MOD - 2) % MOD) * pow(pow(stats.get(i).f, l), MOD - 2) % MOD; /* range special mul / (range mul ^ (l - 1)) */
	    tree.set(i, (a % MOD * (b % MOD)) % MOD);
	    return tree.get(i);
	  }

	  void update(int l, int r, long k) {
	    update(0, 0, n - 1, l, r, k);
	  }

	  long update(int i, int tl, int tr, int ql, int qr, long k) {
	    if (ql <= tl && tr <= qr) {
	      lazy.get(i).f += k * (tl - ql + 1);
	      lazy.get(i).s += k;
	      eval_lazy(i, tl, tr);
	      return tree.get(i);
	    }
	    if (tl > tr || tr < ql || qr < tl || tl == tr) {
			eval_lazy(i, tl, tr);
			return tree.get(i);
		}
		
		if (tl != tr) {
	      lazy.get(i * 2 + 1).f += lazy.get(i).f;
	      lazy.get(i * 2 + 1).s += lazy.get(i).s;
	      lazy.get(i * 2 + 2).f += lazy.get(i).f + ((tr - tl) / 2 + 1) * lazy.get(i).s;
	      lazy.get(i * 2 + 2).s += lazy.get(i).s;
	    }
		lazy.set(i, new Pair(0, 0));

	    int mid = (tl + tr) / 2;
	    long a = update(2 * i + 1, tl, mid, ql, qr, k),
	       b = update(2 * i + 2, mid + 1, tr, ql, qr, k);
	    tree.set(i, (a % MOD * (b % MOD)) % MOD);
	    return tree.get(i);
	  }

	  long query(int l, int r) {
	    return query(0, 0, n-1, l, r);
	  }

	  long query(int i, int tl, int tr, int ql, int qr) {    
	  eval_lazy(i, tl, tr);
	    if (ql <= tl && tr <= qr) {
			
			return tree.get(i);
		}
	    if (tl > tr || tr < ql || qr < tl) return 1;

	    int mid = (tl + tr) / 2;
	    long a = query(2 * i + 1, tl, mid, ql, qr),
	          b = query(2 * i + 2, mid + 1, tr, ql, qr);
	    return (a % MOD * (b % MOD)) % MOD;
	  }

	  void eval_lazy(int i, int l, int r) {
		if (lazy.get(i).f == 0 && lazy.get(i).s == 0) return;
	    long x = pow(stats.get(i).f, lazy.get(i).f);
	    long y = pow(stats.get(i).s, lazy.get(i).s);
	    tree.set(i, tree.get(i) * ((x * y) % MOD) % MOD);

	    if (l != r) {
	      lazy.get(i * 2 + 1).f += lazy.get(i).f;
	      lazy.get(i * 2 + 1).s += lazy.get(i).s;
	      lazy.get(i * 2 + 2).f += lazy.get(i).f + ((r - l) / 2 + 1) * lazy.get(i).s;
	      lazy.get(i * 2 + 2).s += lazy.get(i).s;
	    }

	    lazy.set(i, new Pair(0, 0));
	  }
	}

}
