package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_4179 {

    static class Node {

        int i;
        int j;

        Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int R = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);

        char[][] board = new char[1001][1001];
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        Queue<Node> J = new LinkedList<Node>();
        Queue<Node> F = new LinkedList<Node>();
        int[][] fire = new int[1001][1001];
        int[][] visited = new int[1001][1001];

        for (int i = 0; i < R; i++) {
            char[] c = br.readLine().toCharArray();
            for (int j = 0; j < C; j++) {
                board[i][j] = c[j];

                if (board[i][j] == 'J') {
                    J.add(new Node(i, j));
                    visited[i][j] = 1;
                } else if (board[i][j] == 'F') {
                    F.add(new Node(i, j));
                    fire[i][j] = 1;
                }
            }
        }

        while (!F.isEmpty()) {
            Node cur = F.poll();
            int cnt = fire[cur.i][cur.j];

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.i + dx[dir];
                int ny = cur.j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    continue;
                }
                if (fire[nx][ny] != 0 || board[nx][ny] == '#') {
                    continue;
                }
                fire[nx][ny] = cnt + 1;
                F.add(new Node(nx, ny));
            }
        }

        while (!J.isEmpty()) {
            Node cur = J.poll();
            int cnt = visited[cur.i][cur.j];

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.i + dx[dir];
                int ny = cur.j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    System.out.println(cnt);
                    return;
                }
                if (visited[nx][ny] != 0 || board[nx][ny] == '#') {
                    continue;
                }
                if (visited[cur.i][cur.j] + 1 >= fire[nx][ny] && fire[nx][ny] > 0) {
                    continue;
                }
                visited[nx][ny] = cnt + 1;
                J.add(new Node(nx, ny));
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
