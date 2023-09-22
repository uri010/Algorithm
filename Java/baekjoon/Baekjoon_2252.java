package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon_2252 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s[] = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);
        int indegree[] = new int[N + 1];
        ArrayList<Integer> A[] = new ArrayList[N + 1];
        boolean visited[] = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            A[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            A[a].add(b);
            indegree[b]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.add(i);
                visited[i] = true;
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
            for (int next : A[now]) {
                indegree[next]--;
                if (!visited[next] && indegree[next] == 0) {
                    visited[next] = true;
                    q.add(next);
                }
            }
        }
    }
}
