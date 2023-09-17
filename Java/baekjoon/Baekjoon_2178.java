package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon_2178 {

    static int di[] = {1, -1, 0, 0};
    static int dj[] = {0, 0, 1, -1};


    static boolean visited[][];
    static int map[][];
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        visited = new boolean[N][M];
        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            char inputs[] = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                map[i][j] = inputs[j] - '0';
            }
        }

        BFS();
        System.out.println(map[N-1][M-1]);
    }

    private static void BFS() {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            int now[] = queue.poll();
            for (int k = 0; k < 4; k++) {
                int ni = now[0] + di[k];
                int nj = now[1] + dj[k];
                if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
                    continue;
                }
                if (map[ni][nj] != 0 && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    map[ni][nj] = map[now[0]][now[1]] + 1;
                    queue.offer(new int[]{ni, nj});
                }
            }
        }
    }
}
