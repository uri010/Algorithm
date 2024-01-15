package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_13144 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int num[] = new int[N];
        boolean visited[] = new boolean[100001];
        long cnt = 0;
        String input[] = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(input[i]);
        }

        int left = 0, right = 0;
        while (right < N) {
            if (visited[num[right]]) {
                cnt += right - left;
                visited[num[left]] = false;
                left++;
            } else {
                visited[num[right]] = true;
                right++;
            }
        }

        for (int i = left; i < right; i++) {
            cnt += right - i;
        }
        System.out.println(cnt);
    }
}
