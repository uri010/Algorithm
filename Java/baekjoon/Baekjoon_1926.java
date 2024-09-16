package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_1926 {

    static class Node {

        int i, j;

        Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[][] board = new int[501][501];
        boolean[][] visited = new boolean[501][501];

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int paintCnt = 0, maxWidth = 0;

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    Queue<Node> queue = new LinkedList<>();
                    queue.add(new Node(i, j));
                    visited[i][j] = true;
                    paintCnt++;
                    int cnt = 0;

                    while (!queue.isEmpty()) {
                        Node cur = queue.poll();
                        cnt++;

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.i + dx[dir], ny = cur.j + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]
                                || board[nx][ny] != 1) {
                                continue;
                            }
                            visited[nx][ny] = true;
                            queue.add(new Node(nx, ny));
                        }
                    }
                    if (cnt > maxWidth) {
                        maxWidth = cnt;
                    }
                }
            }
        }
        System.out.println(paintCnt + "\n" + maxWidth);
    }
}
