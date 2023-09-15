package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1427 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char N[] = br.readLine().toCharArray();

        for (int i = 0; i < N.length; i++) {
            int maxIndex = i;
            for (int j = i; j < N.length; j++) {
                if (N[maxIndex] < N[j]) {
                    maxIndex = j;
                }
            }
            char tmp = N[maxIndex];
            N[maxIndex] = N[i];
            N[i] = tmp;
        }

        for (int i = 0; i < N.length; i++) {
            System.out.print(N[i]);
        }

    }
}
