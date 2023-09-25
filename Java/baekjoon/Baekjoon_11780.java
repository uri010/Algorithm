package baekjoon;

import java.awt.print.Pageable;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Baekjoon_11780 {

    static int[][] route;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        dist = new int[N + 1][N + 1];
        route = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = 1000000000;
                }
            }
        }
        for (int i = 0; i < M; i++) {
            String str[] = br.readLine().split(" ");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            int c = Integer.parseInt(str[2]);
            if (dist[a][b] > c) {
                dist[a][b] = c;
            }
            route[a][b] = a;
        }

        for (int k = 1; k <= N; k++) {
            for (int s = 1; s <= N; s++) {
                for (int e = 1; e <= N; e++) {
                    if (dist[s][k] + dist[k][e] < dist[s][e]) {
                        dist[s][e] = dist[s][k] + dist[k][e];
                        route[s][e] = route[k][e];
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] != 1000000000) {
                    System.out.print(dist[i][j] + " ");
                } else {
                    System.out.print(0 + " ");
                }
            }
            System.out.println();
        }

        for (int i = 1; i <= N; i++) {
            PrintPath(i, N);
        }
    }

    private static void PrintPath(int s, int N) {
        for (int e = 1; e <= N; e++) {
            if (e == s) {
                System.out.println(0);
            } else {
                Stack<Integer> st = new Stack<>();
                int idx = route[s][e];
                while (idx != 0) {
                    st.push(idx);
                    idx = route[s][idx];
                }
                if (st.empty()) {
                    System.out.println(0);
                } else {
                    System.out.print(st.size() + 1 + " ");
                    while (!st.empty()) {
                        System.out.print(st.peek() + " ");
                        st.pop();
                    }
                    System.out.println(e);
                }
            }
        }
    }
}
