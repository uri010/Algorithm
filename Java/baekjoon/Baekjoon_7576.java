package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_7576 {

    static class Node {

        int cnt;
        int i;
        int j;

        Node(int cnt, int i, int j) {
            this.cnt = cnt;
            this.i = i;
            this.j = j;
        }
    }

    static int N, M;
    static int[][] board;

    static boolean isAllRipen() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        M = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);
        board = new int[N][M];
        boolean[][] visited = new boolean[N][M];

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        Queue<Node> q = new LinkedList<Node>();
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                if (board[i][j] == 1) {
                    q.add(new Node(0, i, j));
                    visited[i][j] = true;
                }
            }
        }

        if (isAllRipen()) {
            System.out.println(0);
            return;
        }

        int maxCnt = 0;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (maxCnt < cur.cnt) {
                maxCnt = cur.cnt;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.i + dx[dir];
                int ny = cur.j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (board[nx][ny] == -1) {
                    visited[nx][ny] = true;
                } else if (board[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    board[nx][ny] = 1;
                    q.add(new Node(cur.cnt + 1, nx, ny));
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(maxCnt);
    }
}
