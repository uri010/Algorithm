package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_11050 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int arr[][] = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i][0] = 1;
            arr[i][i] = 1;
            arr[i][1] = i;
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
        System.out.println(arr[N][K]);
    }
}
