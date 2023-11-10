package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_20437 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            char[] W = br.readLine().toCharArray();
            int K = Integer.parseInt(br.readLine());
            List lengths = new ArrayList();
            int[] alphabet = new int[26];
            for (int i = 0; i < W.length; i++) {
                alphabet[W[i] - 'a']++;
            }

            for (int i = 0; i < W.length; i++) {
                if (alphabet[W[i] - 'a'] < K) {
                    continue;
                }
                int cnt = 0;
                for (int j = i; j < W.length; j++) {
                    if (W[i] == W[j]) {
                        cnt++;
                    }
                    if (cnt == K) {
                        lengths.add(j - i + 1);
                        break;
                    }
                }
            }
            Collections.sort(lengths);
            if (lengths.isEmpty()) {
                sb.append(-1 + "\n");
            } else {
                sb.append(lengths.get(0) + " " + lengths.get(lengths.size() - 1) + "\n");
            }
        }
        System.out.println(sb);
    }
}
