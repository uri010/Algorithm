package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon_11437 {

    static int N;
    static Node P[];
    static ArrayList<Integer> map[];
    static boolean visited[];

    static class Node {

        int par;
        int depth;

        Node(int num, int depth) {
            this.par = num;
            this.depth = depth;
        }
    }

    public static void BFS() {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        visited[1] = true;
        P[1] = new Node(0, 0);
        while (!q.isEmpty()) {
            int now = q.poll();
            int depth = P[now].depth;

            for (int next : map[now]) {
                if (!visited[next]) {
                    q.add(next);
                    visited[next] = true;
                    P[next] = new Node(now, depth + 1);
                }
            }
        }
    }

    public static void LCA(int i, int j) {
        if (i == j) {
            System.out.println(i);
            return;
        } else {
            if (P[i].depth < P[j].depth) {
                j = P[j].par;
            } else {
                i = P[i].par;
            }
            LCA(i, j);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new ArrayList[N + 1];
        P = new Node[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i <= N; i++) {
            map[i] = new ArrayList<>();
        }

        for (int i = 0; i < N - 1; i++) {
            String input[] = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            map[a].add(b);
            map[b].add(a);
        }

        BFS();
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            String input[] = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            LCA(a, b);
        }

    }

}
