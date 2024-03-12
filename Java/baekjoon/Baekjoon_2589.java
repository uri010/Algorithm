package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_2589 {

    static int H, W;
    static String map[] = new String[51];
    static int maxDist = 0;
    static int di[] = {1, -1, 0, 0};
    static int dj[] = {0, 0, 1, -1};

    static class Pair {

        int i;
        int j;

        Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }

    static class CntPair {

        int cnt;
        int i;
        int j;

        CntPair(int cnt, int i, int j) {
            this.i = i;
            this.j = j;
            this.cnt = cnt;
        }
    }

    static boolean isValid(int i, int j) {
        return i >= 0 && i < H && j >= 0 && j < W;
    }

    static void BFS(Pair pair) {
        boolean visited[][] = new boolean[H][W];
        Queue<CntPair> queue = new LinkedList<>();
        queue.add(new CntPair(0, pair.i, pair.j));
        visited[pair.i][pair.j] = true;

        while (!queue.isEmpty()) {
            CntPair cur = queue.poll();

            maxDist = Math.max(maxDist, cur.cnt);

            for (int k = 0; k < 4; k++) {
                int ni = cur.i + di[k];
                int nj = cur.j + dj[k];
                if (!isValid(ni, nj) || visited[ni][nj] || map[ni].charAt(nj) != 'L') {
                    continue;
                }
                visited[ni][nj] = true;
                queue.add(new CntPair(cur.cnt + 1, ni, nj));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        H = Integer.parseInt(input[0]);
        W = Integer.parseInt(input[1]);

        List<Pair> list = new ArrayList<Pair>();

        for (int i = 0; i < H; i++) {
            map[i] = br.readLine();
            for (int j = 0; j < map[i].length(); j++) {
                if (map[i].charAt(j) == 'L') {
                    list.add(new Pair(i, j));
                }
            }
        }

        for (Pair pair : list) {
            BFS(pair);
        }
        System.out.println(maxDist);
    }
}
