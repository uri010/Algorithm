package programmers;

import java.util.*;

class Rank {

    static ArrayList<Integer> edges[];
    static int[][] cnt;

    static void DFS(int cur, int r, boolean[] visited) {
        visited[cur] = true;
        if (cur != r) {
            cnt[r][0]++;
            cnt[cur][1]++;
        }
        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur].get(i);
            if (!visited[next]) {
                DFS(next, r, visited);
            }
        }
    }

    public int solution(int n, int[][] results) {
        int answer = 0;
        edges = new ArrayList[n + 1];
        cnt = new int[n + 1][2];
        for (int i = 0; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < results.length; i++) {
            int winner = results[i][0];
            int loser = results[i][1];
            edges[winner].add(loser);
        }

        for (int i = 1; i <= n; i++) {
            boolean visited[] = new boolean[n + 1];
            DFS(i, i, visited);
        }

        for (int i = 1; i <= n; i++) {
            if (cnt[i][0] + cnt[i][1] == n - 1) {
                answer++;
            }
        }
        return answer;
    }
}