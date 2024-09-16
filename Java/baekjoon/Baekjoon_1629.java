package baekjoon;

import java.io.*;

public class Baekjoon_1629 {

    static long pow(long a, long b, long c) {
        if (b == 1) {
            return a % c;
        }
        long val = pow(a, b / 2, c);
        val = val * val % c;
        if (b % 2 == 0) {
            return val;
        }
        return val * a % c;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);
        System.out.println(pow(a, b, c));
    }
}
