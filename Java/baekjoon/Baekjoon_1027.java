package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1027 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String input[] = br.readLine().split(" ");
        int buildings[] = new int[N];
        int cnt[] = new int[N];
        for (int i = 0; i < N; i++) {
            buildings[i] = Integer.parseInt(input[i]);
        }

        for (int i = 0; i < N; i++) {
            double maxGradient = -1000000000;

            for (int j = i + 1; j < N; j++) {
                int h = buildings[j] - buildings[i];
                int w = j - i;
                double g = h * 1.0 / w;

                if (g <= maxGradient) {
                    continue;
                }
                maxGradient = g;
                cnt[i]++;
                cnt[j]++;
            }
        }

        int answer = 0;
        for(int i=0; i < N; i++){
            answer = Math.max(answer, cnt[i]);
        }
        System.out.println(answer);
    }

}
