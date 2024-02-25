package programmers;

import java.util.*;

public class ConnectIsland {

    static public int par[] = new int[101];

    static int getParent(int v) {
        if (par[v] == v) {
            return v;
        }
        return par[v] = getParent(par[v]);
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        Arrays.sort(costs, new Comparator<int[]>() {
            public int compare(int[] s1, int[] s2) {
                return s1[2] - s2[2];
            }
        });

        for (int[] ints : costs) {
            int v = getParent(ints[0]);
            int w = getParent(ints[1]);
            int cost = ints[2];

            if (v != w) {
                par[v] = w;
                answer += cost;
            }
        }
        return answer;
    }
}
