package baekjoon;

import java.io.*;

public class Baekjoon_11659 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inputs[] = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int M = Integer.parseInt(inputs[1]);
        String nums[] = br.readLine().split(" ");
        int S[] = new int[N + 1];
        S[0] = 0;

        for (int i = 1; i <= N; i++) {
            S[i] = Integer.parseInt(nums[i - 1]) + S[i - 1];
        }

        for (int k = 0; k < M; k++) {
            String bound[] = br.readLine().split(" ");
            int i = Integer.parseInt(bound[0]);
            int j = Integer.parseInt(bound[1]);
            bw.write(Integer.toString(S[j] - S[i - 1]) + "\n");
        }
        bw.flush();
        bw.close();
    }
}
