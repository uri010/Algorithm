package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Baekjoon_1920 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String inputs[] = br.readLine().split(" ");
        int A[] = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(inputs[i]);
        }
        Arrays.sort(A);

        int M = Integer.parseInt(br.readLine());
        inputs = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            int target = Integer.parseInt(inputs[i]);
            int left = 0;
            int right = N - 1;
            int flag = 0;
            while (left <= right) {
                int midIndex = (left + right) / 2;
                int midValue = A[midIndex];
                if (midValue > target) {
                    right = midIndex - 1;
                } else if (midValue < target) {
                    left = midIndex + 1;
                } else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }
}
