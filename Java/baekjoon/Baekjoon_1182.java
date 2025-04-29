package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1182 {
    static int N, S;
    static int cnt = 0;
    static int[] arr = new int[21];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        S = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        func(0, 0);
        if (S == 0) cnt--;
        System.out.println(cnt);
    }

    private static void func(int idx, int total) {
        if (idx == N) {
            if (total == S) cnt++;
            return;
        }

        func(idx + 1, total);
        func(idx + 1, total + arr[idx]);
    }
}
