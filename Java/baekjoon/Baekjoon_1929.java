package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1929 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);
        boolean arr[] = new boolean[N + 1];
        arr[1] = true;
        for (int i = 2; i <= N; i++) {
            if (arr[i]) {
                continue;
            }
            for (int j = i + i; j <= N; j = j + i) {
                if (arr[j]) {
                    continue;
                }
                arr[j] = true;
            }
        }
        for (int i = M; i <= N; i++) {
            if (!arr[i]) {
                System.out.println(i);
            }
        }
    }

}
