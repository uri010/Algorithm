package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_2018 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 1;
        int sum = 1;
        int startIndex = 1;
        int endIndex = 1;

        while (endIndex != N) {
            if( sum == N ) {
                count++;
                endIndex++;
                sum += endIndex;
            }
            else if( sum > N) {
                sum -= startIndex;
                startIndex++;
            }
            else {
                endIndex++;
                sum += endIndex;
            }
        }
        System.out.println(count);
    }

}
