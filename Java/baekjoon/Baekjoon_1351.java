package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Baekjoon_1351 {

    static Map<Long, Long> map = new HashMap<>();
    static int P, Q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        long N = Long.parseLong(input[0]);
        P = Integer.parseInt(input[1]);
        Q = Integer.parseInt(input[2]);

        System.out.println(Solve(N));
    }

    static long Solve(long num) {
        if (num == 0) {
            return 1;
        }
        if (map.containsKey(num)) {
            return map.get(num);
        }

        long a = (long) Math.floor(num / P);
        long b = (long) Math.floor(num / Q);

        map.put(num, Solve(a) + Solve(b));
        return map.get(num);
    }
}
