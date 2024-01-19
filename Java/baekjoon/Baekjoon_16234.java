package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_16234 {

    static int N, L, R;
    static int arr[][];
    static boolean visited[][];
    static int sum;
    static ArrayList<Coor> coor;
    static int di[] = new int[]{0, 1, -1, 0};
    static int dj[] = new int[]{1, 0, 0, -1};

    public static void BFS(int i, int j) {
        Queue<Coor> queue = new LinkedList<>();
        coor = new ArrayList<>();
        queue.offer(new Coor(i, j));
        visited[i][j] = true;
        coor.add(new Coor(i, j));
        sum = arr[i][j];

        while (!queue.isEmpty()) {
            Coor cur = queue.poll();
            i = cur.i;
            j = cur.j;

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= N || nj >= N || visited[ni][nj]) {
                    continue;
                }

                if (Math.abs(arr[ni][nj] - arr[i][j]) >= L
                    && Math.abs(arr[ni][nj] - arr[i][j]) <= R) {
                    visited[ni][nj] = true;
                    queue.offer(new Coor(ni, nj));
                    coor.add(new Coor(ni, nj));
                    sum += arr[ni][nj];
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        R = Integer.parseInt(input[2]);

        arr = new int[N + 1][N + 1];
        boolean isUnion = true;
        sum = 0;
        int days = 0;

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < input.length; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }

        while (isUnion) {
            isUnion = false;
            visited = new boolean[N + 1][N + 1];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j]) {
                        BFS(i, j);
                        if (coor.size() >= 2) {
                            isUnion = true;
                            for (Coor co : coor) {
                                arr[co.i][co.j] = sum / coor.size();
                            }
                        }
                    }
                }
            }
            if (isUnion) {
                days++;
            }
        }
        System.out.println(days);
    }

    public static class Coor {

        int i;
        int j;

        Coor(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}
