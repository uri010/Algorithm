package baekjoon;

import java.awt.print.Pageable;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_19941 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);
        char tables[] = br.readLine().toCharArray();
        boolean visited[] = new boolean[N];
        int ans = 0;

        for (int i = 0; i < tables.length; i++) {
            boolean isFind = false;
            if (tables[i] == 'P') {
                for (int j = K; j >= 1; j--) {
                    if (i - j >= 0 && tables[i - j] == 'H' && !visited[i - j]) {
                        visited[i - j] = true;
                        ans++;
                        isFind = true;
                        break;
                    }
                }
                if (!isFind) {
                    for (int j = 1; j <= K; j++) {
                        if (i + j < N && tables[i + j] == 'H' && !visited[i + j]) {
                            visited[i + j] = true;
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
