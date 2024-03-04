package baekjoon;

import java.io.*;

public class Baekjoon_2559 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int S[] = new int[N + 1];

        input = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            S[i] = S[i - 1] + Integer.parseInt(input[i - 1]);
        }

        int maxNum = -100000001;
        for (int i = 0; i <= N - K; i++) {
            maxNum = Math.max(maxNum, S[i + K] - S[i]);
        }
        System.out.println(maxNum);
    }
}
