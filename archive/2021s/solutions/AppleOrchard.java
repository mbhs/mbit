import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AppleOrchard {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n, m, x, y, a, b, c, d;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        
        int ans = 1000000000;
        for(int i = -2000; i <= 2000; i++){
            int applesNeeded = a + i*c - n;
            int bonesNeeded = b - i*d - m;
            int subAns = 0;
            if(applesNeeded > 0){
                subAns += applesNeeded * x;
            }
            if(bonesNeeded > 0){
                subAns += bonesNeeded * y;
            }
            ans = Math.min(ans, subAns);
        }
        System.out.println(ans);
    }
}
