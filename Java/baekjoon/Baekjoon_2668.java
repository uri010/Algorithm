package baekjoon;

import com.sun.source.tree.Tree;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;

public class Baekjoon_2668 {

    static int[] input;
    static boolean[] visited;
    static int N;
    static Set<Integer> answer = new TreeSet<>();
    static boolean isCycle;

    static void init() {
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
        }
    }

    static void DFS(int firstNum, int num) {
        if (visited[num]) {
            if (firstNum == num) {
                isCycle = true;
                answer.add(num);
            }
            return;
        }
        visited[num] = true;
        DFS(firstNum, input[num]);

        if (isCycle) {
            answer.add(num);
            answer.add(input[num]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        input = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            input[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 1; i <= N; i++) {
            visited[i] = true;
            DFS(i, input[i]);
            init();
            isCycle = false;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(answer.size() + "\n");
        for (int a : answer) {
            sb.append(a + "\n");
        }
        System.out.println(sb);

    }
}
