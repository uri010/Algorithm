package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_1976 {
    static boolean visited[];
    static ArrayList<Integer>[] edges;

    static void DFS(int cur) {
        visited[cur] = true;

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur].get(i);
            if (!visited[next]) {
                DFS(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        visited = new boolean[N + 1];

        edges = new ArrayList[N + 1];
        for (int i = 0; i < N + 1; i++) {
            edges[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            String input[] = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                if (input[j].equals("1")) {
                    edges[i + 1].add(j + 1);
                }
            }
        }

        String plan[] = br.readLine().split(" ");
        DFS(Integer.parseInt(plan[0]));

        for(int i=0; i < plan.length; i++){
            if( !visited[Integer.parseInt(plan[i])]){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
