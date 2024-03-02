package baekjoon;

import java.io.*;

public class Baekjoon_11655 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        char input[] = br.readLine().toCharArray();

        for (int i = 0; i < input.length; i++) {
            if (input[i] == ' ') {
                sb.append(' ');
            } else {
                if (input[i] >= 'a' && input[i] <= 'z') {
                    if (input[i] - 'a' < 13) {
                        input[i] += 13;
                    } else {
                        input[i] -= 13;
                    }
                } else if (input[i] >= 'A' && input[i] <= 'Z') {
                    if (input[i] - 'A' < 13) {
                        input[i] += 13;
                    } else {
                        input[i] -= 13;
                    }
                }
                sb.append(input[i]);
            }
        }
        System.out.println(sb);
    }
}
