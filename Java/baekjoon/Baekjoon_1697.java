package baekjoon;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Baekjoon_1697 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int MAX = 100000;
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[] arr = new int[MAX + 1];
        for (int i = 0; i < MAX + 1; i++) {
            arr[i] = MAX;
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        arr[n] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur + 1 <= MAX && arr[cur + 1] > arr[cur] + 1) {
                arr[cur + 1] = arr[cur] + 1;
                q.add(cur + 1);
            }
            if (cur - 1 >= 0 && arr[cur - 1] > arr[cur] + 1) {
                arr[cur - 1] = arr[cur] + 1;
                q.add(cur - 1);
            }
            if (cur * 2 <= MAX && arr[cur * 2] > arr[cur] + 1) {
                arr[cur * 2] = arr[cur] + 1;
                q.add(cur * 2);
            }
        }
        System.out.println(arr[k]);
    }
}
