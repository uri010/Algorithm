package programmers;

import java.util.*;

public class FurthestNode {

    static class Node {

        int vertex;
        int cnt;

        Node(int vertex, int cnt) {
            this.vertex = vertex;
            this.cnt = cnt;
        }
    }

    public int solution(int n, int[][] edge) {
        int answer = 0;
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < edge.length; i++) {
            int v = edge[i][0];
            int w = edge[i][1];
            edges.get(v).add(w);
            edges.get(w).add(v);
        }

        Queue<Node> queue = new LinkedList<>();
        boolean visited[] = new boolean[n + 1];
        int dp[] = new int[n + 1];
        int maxDepth = 0;
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
        queue.add(new Node(1, 0));
        visited[1] = true;
        while (!queue.isEmpty()) {
            Node cur = queue.peek();
            queue.poll();

            maxDepth = Math.max(maxDepth, cur.cnt);
            dp[cur.vertex] = cur.cnt;

            for (int i = 0; i < edges.get(cur.vertex).size(); i++) {
                int next = edges.get(cur.vertex).get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(new Node(next, cur.cnt + 1));
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == maxDepth) {
                answer++;
            }
        }
        return answer;
    }
}
