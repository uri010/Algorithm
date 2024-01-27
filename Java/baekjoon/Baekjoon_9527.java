package baekjoon;

import java.io.*;

public class Baekjoon_9527 {

    static long d[] = new long[55];

    static long CountOne(long num) {
        long ret = num & 1;

        for (int i = 54; i > 0; i--) {
            if ((num & (1L << i)) != 0) {
                ret += d[i - 1] + (num - (1L << i) + 1);
                num -= 1L << i;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        long A = Long.parseLong(input[0]);
        long B = Long.parseLong(input[1]);

        d[0] = 1;
        for (int i = 1; i < 55; i++) {
            d[i] = 2 * d[i - 1] + (1L << i);
        }
        System.out.println(CountOne(B) - CountOne(A - 1));
    }
}