package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_12919 {

    static String s;
    static String t;

    static void Solve(String str) {
        if (str.equals(s)) {
            System.out.println(1);
            System.exit(0);
        }

        if (str.length() == 1) {
            return;
        }

        String tmp;
        if (str.charAt(str.length() - 1) == 'A') {
            tmp = str.substring(0, str.length() - 1);
            Solve(tmp);
        }

        if (str.charAt(0) == 'B') {
            tmp = str.substring(1, str.length());
            StringBuffer sb = new StringBuffer(tmp);
            Solve(sb.reverse().toString());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
        t = br.readLine();

        Solve(t);
        System.out.println(0);
    }

}
