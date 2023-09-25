package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Edge {

    int start;

    int end;
    int weight;

    Edge(int start, int end, int weight) {
        this.start = start;
        this.end = end;
        this.weight = weight;
    }
}

public class Baekjoon_11657 {

    static final int INF = 987654321;
    static Edge edges[];
    static long dist[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str[] = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);

        dist = new long[N + 1];
        edges = new Edge[M];
        for (int i = 1; i <= N; i++) {
            dist[i] = INF;
        }
        for (int i = 0; i < M; i++) {
            str = br.readLine().split(" ");
            int A = Integer.parseInt(str[0]);
            int B = Integer.parseInt(str[1]);
            int C = Integer.parseInt(str[2]);

            edges[i] = new Edge(A, B, C);
        }
        dist[1] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                Edge edge = edges[j];
                if (dist[edge.start] != INF && dist[edge.start] + edge.weight < dist[edge.end]) {
                    dist[edge.end] = dist[edge.start] + edge.weight;
                }
            }
        }

        boolean isCycle = false;
        for (int j = 0; j < M; j++) {
            Edge edge = edges[j];
            if (dist[edge.start] != INF && dist[edge.start] + edge.weight < dist[edge.end]) {
                isCycle = true;
                break;
            }
        }
        if (isCycle) {
            System.out.println(-1);
        } else {
            for (int i = 2; i <= N; i++) {
                if (dist[i] == INF) {
                    System.out.println(-1);
                } else {
                    System.out.println(dist[i]);
                }
            }
        }
    }
}
