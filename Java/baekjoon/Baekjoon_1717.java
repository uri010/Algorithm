package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1717 {

    static int n, m;
    static int par[];

    static int Find(int a) {
        if (par[a] == a) {
            return a;
        }
        return par[a] = Find(par[a]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s[] = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);

        par = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < m; i++) {
            s = br.readLine().split(" ");
            int operator = Integer.parseInt(s[0]);
            int a = Find(Integer.parseInt(s[1]));
            int b = Find(Integer.parseInt(s[2]));

            if (operator == 0) {
                if (a != b) {
                    if (a < b) {
                        par[b] = a;
                    } else {
                        par[a] = b;
                    }
                }
            } else {
                if (a == b) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
