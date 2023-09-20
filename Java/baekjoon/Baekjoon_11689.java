package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_11689 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        long pi = n;
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                pi = pi / i * (i - 1);
            }
            while (n % i == 0) {
                n /= i;
            }

        }
        if (n != 1) {
            pi = pi / n * (n - 1);
        }
        System.out.println(pi);
    }
}
