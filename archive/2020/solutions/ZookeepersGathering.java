import java.util.*;

public class ZookeepersGathering {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		SegTree st = new SegTree(n + 1);
		for (int i = 0; i < 4; i++) {
			int m = sc.nextInt();
			for (int j = 0; j < m; j++) {
				int l = sc.nextInt(), r = sc.nextInt();
				st.update(1, l, r, 1);
			}
		}

		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			sc.nextInt();
			int t = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
			if (t == 0)
				st.update(1, l, r, 1);
			else
				st.update(1, l, r, -1);
			System.out.println(st.st[1].ans[0]);
		}

		sc.close();

	}

	static class SegTree {

		static class Node {
			int l, r, lazy;
			int[] pref, suff, ans;

			Node(int l, int r) {
				this.l = l;
				this.r = r;
				lazy = 0;
				pref = new int[] { this.r - this.l + 1, 0, 0, 0, 0 };
				suff = new int[] { this.r - this.l + 1, 0, 0, 0, 0 };
				ans = new int[] { this.r - this.l + 1, 0, 0, 0, 0 };
			}

			void merge(Node a, Node b) {
				for (int i = 0; i <= 4; i++) {
					pref[i] = a.pref[i] + (a.pref[i] == a.r - a.l + 1 ? b.pref[i] : 0);
					suff[i] = b.suff[i] + (b.suff[i] == b.r - b.l + 1 ? a.suff[i] : 0);
					ans[i] = Math.max(Math.max(a.ans[i], b.ans[i]), a.suff[i] + b.pref[i]);
				}
			}

			void push(int val) {
				lazy += val;
			}

			void apply() {
				if (lazy > 0) {
					for (int i = 4; i >= lazy; i--) {
						pref[i] = pref[i - lazy];
						suff[i] = suff[i - lazy];
						ans[i] = ans[i - lazy];
						pref[i - lazy] = suff[i - lazy] = ans[i - lazy] = 0;
					}
				} else {
					lazy = -lazy;
					for (int i = 0; i <= 4 - lazy; i++) {
						pref[i] = pref[i + lazy];
						suff[i] = suff[i + lazy];
						ans[i] = ans[i + lazy];
						pref[i + lazy] = suff[i + lazy] = ans[i + lazy] = 0;
					}
				}
				lazy = 0;
			}
		}

		int n;
		Node[] st;

		SegTree(int n) {
			this.n = n;
			st = new Node[4 * n];
			build(1, 0, n - 1);
		}

		void build(int p, int l, int r) {
			st[p] = new Node(l, r);
			if (l != r) {
				int m = (l + r) / 2;
				build(2 * p, l, m);
				build(2 * p + 1, m + 1, r);
			}
		}

		void push(int p) {
			if (st[p].lazy != 0) {
				if (st[p].l != st[p].r) {
					st[2 * p].push(st[p].lazy);
					st[2 * p + 1].push(st[p].lazy);
				}
				st[p].apply();
			}
		}

		void update(int p, int i, int j, int val) {
			if (st[p].l == i && st[p].r == j) {
				st[p].push(val);
				push(p);
				return;
			}

			push(p);

			int m = (st[p].l + st[p].r) / 2;
			if (j <= m) {
				update(2 * p, i, j, val);
				push(2 * p + 1);
			} else if (i > m) {
				push(2 * p);
				update(2 * p + 1, i, j, val);
			} else {
				update(2 * p, i, m, val);
				update(2 * p + 1, m + 1, j, val);
			}
			st[p].merge(st[2 * p], st[2 * p + 1]);
		}
	}

}
