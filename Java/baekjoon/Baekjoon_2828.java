package baekjoon;

import java.io.*;

public class Baekjoon_2828 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int J = Integer.parseInt(br.readLine());

        int left = 1;
        int right = M;
        int distance = 0;
        for (int i = 0; i < J; i++) {
            int idx = Integer.parseInt(br.readLine());
            if (idx < left) {
                int diff = Math.abs(left - idx);
                distance += diff;
                left -= diff;
                right -= diff;
            } else if (idx > right) {
                int diff = idx - right;
                distance += diff;
                left += diff;
                right += diff;
            }
        }
        System.out.println(distance);
    }

}
