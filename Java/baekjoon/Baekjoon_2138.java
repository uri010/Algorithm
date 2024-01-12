package baekjoon;

import java.util.*;
import java.io.*;

public class Baekjoon_2138 {

    static int N;
    static int now[] = new int[100001];
    static int copyNow[] = new int[100001];
    static int target[] = new int[100001];
    static int result;

    static void Push(int bulb[], int switchNum) {
        for (int i = switchNum - 1; i <= switchNum + 1; i++) {
            if (i >= 0 && i < N) {
                bulb[i] = 1-bulb[i];
            }
        }
    }

    static boolean isTarget(int bulb[]) {
        result = 0;
        for(int i=1; i <N; i++){
            if( bulb[i-1] != target[i-1]) {
                Push(bulb, i);
                result++;
            }
        }

        // 스위치를 눌러 target을 만들 수 있는지 확인
        for(int i=0; i < N; i++){
            if( bulb[i] != target[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans = -1;
        N = Integer.parseInt(br.readLine());
        char[] input = br.readLine().toCharArray();
        for (int i = 0; i < input.length; i++) {
            now[i] = input[i] - '0';
            copyNow[i] = now[i];
        }
        input = br.readLine().toCharArray();
        for (int i = 0; i < input.length; i++) {
            target[i] = input[i] - '0';
        }

        //0번을 안 눌렀을 때
        if( isTarget(copyNow)) {
            if( ans == -1) ans = result;
            else ans = Math.min(ans, result);
        }
        //0번을 눌렀을 때
        Push(now, 0);

        if (isTarget(now)) {
            result++;
            if( ans == -1) ans = result;
            else ans = Math.min(ans, result);
        }
        System.out.println(ans);
    }

}
