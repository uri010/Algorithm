package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_14719 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int H = Integer.parseInt(input[0]);
        int W = Integer.parseInt(input[1]);
        int map[][] = new int[H][W];
        int ans = 0;

        input = br.readLine().split(" ");
        for (int i = 0; i < W; i++) {
            int height = Integer.parseInt(input[i]);
            for (int j = 0; j < height; j++) {
                map[j][i] = 1;
            }
        }

        for (int i = 0; i < H; i++) {
            boolean flag = false;
            int cnt = 0;
            for (int j = 0; j < W; j++) {
                if (flag) {
                    if (j != W - 1 && map[i][j] == 0) {
                        cnt++;
                    } else if (map[i][j] == 1) {
                        ans += cnt;
                        cnt = 0;
                    }
                } else if (map[i][j] == 1) {
                    flag = true;
                }
            }
        }
        System.out.println(ans);
    }

}
