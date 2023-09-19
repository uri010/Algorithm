package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1541 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str[] = br.readLine().split("-");
        int ans = 0;
        for (int i = 0; i < str.length; i++) {

            String tmp[] = str[i].split("\\+");
            int sum = 0;
            for (int j = 0; j < tmp.length; j++) {
                sum += Integer.parseInt(tmp[j]);
            }
            if (i == 0) {
                ans += sum;
            } else {
                ans -= sum;
            }
        }
        System.out.println(ans);
    }
}
