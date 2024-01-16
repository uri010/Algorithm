package programmers;

import java.util.*;

public class Network {

    static ArrayList<Integer> edges[];
    static boolean visited[];

    static void DFS(int cur) {
        visited[cur] = true;
        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur].get(i);
            if (!visited[next]) {
                DFS(next);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        edges = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < computers.length; i++) {
            for (int j = 0; j < computers[i].length; j++) {
                if (i == j) {
                    continue;
                }
                if (computers[i][j] == 1) {
                    edges[i].add(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i);
                answer++;
            }
        }
        return answer;
    }
}