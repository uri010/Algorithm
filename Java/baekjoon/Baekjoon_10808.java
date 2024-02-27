package baekjoon;

import java.io.*;

public class Baekjoon_10808 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        char s[] = br.readLine().toCharArray();
        int alphabet[] = new int[26];

        for (int i = 0; i < s.length; i++) {
            alphabet[s[i] - 'a']++;
        }

        for (int i = 0; i < alphabet.length; i++) {
            sb.append(alphabet[i] + " ");
        }
        System.out.println(sb);
    }
}
