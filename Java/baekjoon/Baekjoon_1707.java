package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Baekjoon_1707 {

    static int V, E;
    static ArrayList<Integer> A[];
    static boolean visited[];
    static int check[];
    static boolean flag;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            String input[] = br.readLine().split(" ");
            V = Integer.parseInt(input[0]);
            E = Integer.parseInt(input[1]);
            A = new ArrayList[V + 1];
            visited = new boolean[V + 1];
            check = new int[V + 1];
            flag = false;

            for (int j = 1; j <= V; j++) {
                A[j] = new ArrayList<Integer>();
            }
            for (int j = 0; j < E; j++) {
                input = br.readLine().split(" ");
                int start = Integer.parseInt(input[0]);
                int end = Integer.parseInt(input[1]);
                A[start].add(end);
                A[end].add(start);
            }
            for (int j = 1; j <= V; j++) {
                if (!flag ) {
                    DFS(j);
                } else {
                    break;
                }
            }
            if (!flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    static void DFS(int v) {
        visited[v] = true;
        for (int i : A[v]) {
            if (!visited[i]) {
                check[i] = (check[v] + 1) % 2;
                DFS(i);
            } else if (check[i] == check[v]) {
                flag = true;
                return;
            }
        }
    }
}
