package baekjoon;

import java.io.*;

public class Baekjoon_15989 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int ans[] = new int[10001];
        for (int i = 1; i < 10001; i++) {
            ans[i] = 0;
        }
        ans[0] = 1;
        for (int i = 1; i <= 3; i++) {
            for (int j = i; j < 10001; j++) {
                ans[j] = ans[j] + ans[j - i];
            }
        }
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int n = Integer.parseInt(br.readLine());
            sb.append(ans[n] + "\n");
        }
        System.out.println(sb);
    }
}
