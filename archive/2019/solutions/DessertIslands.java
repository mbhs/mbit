import java.util.*;
import java.io.*;

// By Ayush Varshney
public class DessertIslands {
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        boolean[][] in = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String line = sc.next();
            for (int j = 0; j < m; j++) {
                in[i][j] = 'S' == line.charAt(j);
            }
        }
        DSU map = new DSU(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && in[i - 1][j] == in[i][j]) {
                    map.union(i * m + j, (i - 1) * m + j);
                }
                if (i < n - 1 && in[i + 1][j] == in[i][j]) {
                    map.union(i * m + j, (i + 1) * m + j);
                }
                if (j > 0 && in[i][j - 1] == in[i][j]) {
                    map.union(i * m + j, i * m + (j - 1));
                }
                if (j < m - 1 && in[i][j + 1] == in[i][j]) {
                    map.union(i * m + j, i * m + (j + 1));
                }
            }
        }
        HashSet<Integer> vis = new HashSet<Integer>();
        int island = -1, lake = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis.contains(map.find(i * m + j)))
                    continue;
                if (in[i][j]) {
                    island++;
                } else {
                    lake++;
                }
                vis.add(map.find(i * m + j));
            }
        }
        System.out.println(island + " " + lake);
        sc.close();
    }

    static class DSU {
        int[] rank, parent;
        int n;
        
        // Constructor
        public DSU(int n) {
            rank = new int[n];
            parent = new int[n];
            this.n = n;
            makeSet();
        }
        
        // Creates n sets with single item in each
        void makeSet() {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        // Returns representative of x's set
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        // Unites set with x and set with y
        void union(int x, int y) {
            int xRoot = find(x), yRoot = find(y);
            if (xRoot == yRoot)
                return;
            if (rank[xRoot] < rank[yRoot])
                parent[xRoot] = yRoot;
            else if (rank[yRoot] < rank[xRoot])
                parent[yRoot] = xRoot;
            else {
                parent[yRoot] = xRoot;
                rank[xRoot] = rank[xRoot] + 1;
            }
        }
    }
    
}