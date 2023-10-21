package programmers;

import java.util.*;

class RicochetRobot {
    static int iStart = -1, jStart = -1;
    static boolean visited[][] = new boolean[101][101];
    static int[] di = {1, -1, 0, 0};
    static int[] dj = {0, 0, 1, -1};
    static int answer = 0;

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

    static void BFS(String[] board) {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, iStart, jStart));

        while (!q.isEmpty()) {
            int cnt = q.peek().cnt;
            int i = q.peek().i;
            int j = q.peek().j;
            q.poll();

            if (board[i].charAt(j) == 'G') {
                answer = cnt;
                return;
            }
            for (int k = 0; k < 4; k++) {
                int diri = di[k];
                int dirj = dj[k];

                int ni = i;
                int nj = j;
                if (diri != 0) {
                    while (ni < board.length && ni >= 0 && board[ni].charAt(j) != 'D') {
                        ni += diri;
                    }
                    if (!visited[ni - diri][j]) {
                        q.add(new Node(cnt + 1, ni - diri, j));
                        visited[ni - diri][j] = true;
                    }
                } else if (dirj != 0) {
                    while (nj < board[0].length() && nj >= 0 && board[i].charAt(nj) != 'D') {
                        nj += dirj;
                    }
                    if (!visited[i][nj - dirj]) {
                        q.add(new Node(cnt + 1, i, nj - dirj));
                        visited[i][nj - dirj] = true;
                    }
                }

            }
        }

    }


    public int solution(String[] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                if (board[i].charAt(j) == 'R') {
                    iStart = i;
                    jStart = j;
                    break;
                }
            }
            if (iStart != -1) {
                break;
            }
        }

        BFS(board);
        if (answer != 0) {
            return answer;
        }
        return -1;
    }
}