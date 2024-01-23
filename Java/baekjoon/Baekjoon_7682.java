package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_7682 {

    static boolean xWin;
    static boolean oWin;

    static void checkWinner(String str) {
        xWin = false;
        oWin = false;

        //세로
        for (int i = 0; i < 3; i++) {
            if (str.charAt(i) == str.charAt(i + 3) && str.charAt(i) == str.charAt(i + 6)
                && str.charAt(i) != '.') {
                if (str.charAt(i) == 'X') {
                    xWin = true;
                } else {
                    oWin = true;
                }
            }
        }

        //가로
        for (int i = 0; i < 7; i += 3) {
            if (str.charAt(i) == str.charAt(i + 1) && str.charAt(i) == str.charAt(i + 2)
                && str.charAt(i) != '.') {
                if (str.charAt(i) == 'X') {
                    xWin = true;
                } else {
                    oWin = true;
                }
            }
        }

        //대각선
        if (str.charAt(0) == str.charAt(4) && str.charAt(0) == str.charAt(8)
            && str.charAt(0) != '.') {
            if (str.charAt(0) == 'X') {
                xWin = true;
            } else {
                oWin = true;
            }
        }
        if (str.charAt(2) == str.charAt(4) && str.charAt(2) == str.charAt(6)
            && str.charAt(2) != '.') {
            if (str.charAt(2) == 'X') {
                xWin = true;
            } else {
                oWin = true;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();

        while (!str.equals("end")) {
            checkWinner(str);
            int xCnt = 0;
            int oCnt = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) == 'X') {
                    xCnt++;
                } else if (str.charAt(i) == 'O') {
                    oCnt++;
                }
            }

            if (xWin && !oWin && xCnt == oCnt + 1) {
                sb.append("valid\n");
            } else if (!xWin && oWin && xCnt == oCnt) {
                sb.append("valid\n");
            } else if (!xWin && !oWin && xCnt == 5 && oCnt == 4) {
                sb.append("valid\n");
            } else {
                sb.append("invalid\n");
            }
            str = br.readLine();
        }
        System.out.println(sb);
    }
}
