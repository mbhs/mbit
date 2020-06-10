import java.util.*;

public class SealSharing {

	final static int MOD = 1000000007;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();

		int q = sc.nextInt();
		int maxt = 0;
		ArrayList<Pair> updates = new ArrayList<>();
		for (int i = 0; i < q; i++) {
			int k = sc.nextInt(), t = sc.nextInt();
			maxt = Math.max(maxt, t);
			updates.add(new Pair(k, t));
		}

		ArrayList<Integer> need = new ArrayList<>(), cur = new ArrayList<>();
		ArrayList<ArrayList<Integer>> store = new ArrayList<>();
		TreeSet<Integer> tmp = new TreeSet<>();
		HashMap<Integer, Integer> mapUpdates = new HashMap<>();
		for (Pair x : updates)
			tmp.add(x.second);
		for (int x : tmp)
			need.add(x);
		for (int i = 0; i < need.size(); i++)
			mapUpdates.put(need.get(i), i);
		for (int i = 0; i < n; i++)
			cur.add(0);
		cur.set(0, 1);
		int times = 0;
		for (int x : need) {
			while (times < x) {
				int[] nxt = new int[n];
				for (int i = 0; i < n; i++)
					nxt[i] = cur.get(i) + cur.get((i - 1 + n) % n);
				for (int i = 0; i < n; i++)
					if (nxt[i] >= MOD)
						nxt[i] -= MOD;

				int temp;
				for (int i = 0; i < n; i++) {
					temp = nxt[i];
					nxt[i] = cur.get(i);
					cur.set(i, temp);
				}

				times++;
			}

			store.add((ArrayList<Integer>) cur.clone());
		}

		boolean[] vis = new boolean[n];
		for (Pair u : updates) {
			int k = u.first;
			int t = mapUpdates.get(u.second);
			for (int i = 0; i < n; i++)
				vis[i] = false;
			int[] nxt = new int[n];
			ArrayList<Long> use = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				if (vis[i])
					continue;
				ArrayList<Integer> v = new ArrayList<>();
				int cval = i;
				while (!vis[cval]) {
					vis[cval] = true;
					v.add(cval);
					cval += k;
					if (cval >= n)
						cval -= n;
				}

				if (use.size() == 0) {
					for (int j = 0; j < v.size(); j++)
						use.add(0L);
					for (int j = 0; j < n; j++) {
						int idx = j % use.size();
						use.set(idx, use.get(idx) + store.get(t).get(j));
						if (use.get(idx) >= MOD)
							use.set(idx, use.get(idx) - MOD);
					}
				}

				for (int j = 0; j < v.size(); j++) {
					for (int l = 0; l < v.size(); l++) {
						int idx = (j + l) % v.size();
						nxt[v.get(idx)] += (use.get(l) * a[v.get(j)]) % MOD;
						if (nxt[v.get(idx)] >= MOD)
							nxt[v.get(idx)] -= MOD;
					}
				}
			}

			for (int i = 0; i < n; i++)
				a[i] = nxt[i];
		}

		for (int i = 0; i < n; i++)
			System.out.print(a[i] + " ");
		System.out.println();

		sc.close();

	}

	static class Pair {
		int first, second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}

}
