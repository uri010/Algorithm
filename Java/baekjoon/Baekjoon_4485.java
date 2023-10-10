package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Baekjoon_4485 {

    static int N;
    static int INF = 21000000;
    static int di[] = {1, -1, 0, 0};
    static int dj[] = {0, 0, 1, -1};
    static int arr[][];
    static int dist[][];

    static class Node implements Comparable<Node> {

        int i;
        int j;
        int cost;

        //정점번호, 가중치 저장
        public Node(int i, int j, int cost) {
            this.i = i;
            this.j = j;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }

    }


    static void BFS() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0, arr[0][0]));
        dist[0][0] = arr[0][0];

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.cost > dist[cur.i][cur.j]) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int ni = cur.i + di[k];
                int nj = cur.j + dj[k];
                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    continue;
                }
                int nextCost = cur.cost + arr[ni][nj];
                if (nextCost >= dist[ni][nj]) {
                    continue;
                }
                dist[ni][nj] = nextCost;
                pq.offer(new Node(ni, nj, nextCost));
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        while (true) {
            N = Integer.parseInt(br.readLine());
            if (N == 0) {
                break;
            }
            arr = new int[N][N];
            dist = new int[N][N];

            for (int i = 0; i < N; i++) {
                String input[] = br.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    arr[i][j] = Integer.parseInt(input[j]);
                    dist[i][j] = INF;
                }
            }
            BFS();
            cnt++;
            sb.append("Problem " + cnt + ": " + dist[N - 1][N - 1] + "\n");
        }
        System.out.println(sb);
        br.close();
    }
}
