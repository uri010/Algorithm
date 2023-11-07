package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_2631 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int arr[] = new int[N + 1];
        int dp[] = new int[N + 1];
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 1; i <= N; i++) {
            dp[i] = 1;
            for (int j = 1; j <= i; j++) {
                if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(N - ans);
    }
}
