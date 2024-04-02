package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_2797 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int arr[] = new int[M];
        int ans = 0;
        for (int i = 0; i < M; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);

        int left = 1, right = arr[M - 1];
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0; i < M; i++) {
                cnt += arr[i] / mid;
                if (arr[i] % mid != 0) {
                    cnt++;
                }
            }

            if (cnt <= N) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(ans);
    }

}
