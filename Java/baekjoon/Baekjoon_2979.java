package baekjoon;

import java.io.*;

public class Baekjoon_2979 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int C = Integer.parseInt(input[2]);

        int t[] = new int[101];
        int maxOut = 0;
        for (int i = 0; i < 3; i++) {
            input = br.readLine().split(" ");
            int enter = Integer.parseInt(input[0]);
            int out = Integer.parseInt(input[1]);

            maxOut = Math.max(maxOut, out);

            for (int j = enter; j < out; j++) {
                t[j]++;
            }
        }

        int cost = 0;
        for (int i = 1; i < maxOut; i++) {
            switch (t[i]) {
                case 1:
                    cost += A;
                    break;
                case 2:
                    cost += B * 2;
                    break;
                case 3:
                    cost += C * 3;
                    break;
            }
        }
        System.out.println(cost);
    }
}