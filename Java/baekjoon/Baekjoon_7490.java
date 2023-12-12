package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_7490 {

    static boolean isZero(String str) {
        char[] arr = str.toCharArray();
        int tmp = 0;
        int sum = 0;
        char sign = '+';
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= '0' && arr[i] <= '9') {
                tmp = tmp * 10 + (arr[i] - '0');
                if (i == arr.length - 1) {
                    if (sign == '+') {
                        sum += tmp;
                    } else if( sign == '-'){
                        sum -= tmp;
                    }
                }
            } else if (arr[i] == '+' || arr[i] == '-') {
                if (sign == '+') {
                    sum += tmp;
                } else if( sign == '-'){
                    sum -= tmp;
                }
                tmp = 0;
                sign = arr[i];
            }
        }
        if (sum == 0) {
            return true;
        }
        return false;
    }

    static void DFS(String str, int N, int num) {
        if (num == N) {
            if (isZero(str)) {
                sb.append(str + "\n");
            }
            return;
        }

        DFS(str + " " + (num + 1), N, num + 1);
        DFS(str + "+" + (num + 1), N, num + 1);
        DFS(str + "-" + (num + 1), N, num + 1);
    }

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i=0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            String str = "1";
            DFS(str, N, 1);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
