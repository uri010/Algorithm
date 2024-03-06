package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_2910 {

    static class Info {

        int cnt;
        int idx;

        Info(int cnt, int idx) {
            this.cnt = cnt;
            this.idx = idx;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");

        Map<Integer, Info> map = new HashMap<>();
        for (int i = 0; i < input.length; i++) {
            int n = Integer.parseInt(input[i]);
            if (map.containsKey(n)) {
                Info tmp = map.get(n);
                map.replace(n, new Info(tmp.cnt + 1, tmp.idx));
            } else {
                map.put(n, new Info(1, i));
            }
        }

        List<Integer> keySet = new ArrayList<>(map.keySet());
        keySet.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (map.get(o1).cnt == map.get(o2).cnt) {
                    return map.get(o1).idx - map.get(o2).idx;
                }
                return map.get(o2).cnt - map.get(o1).cnt;
            }
        });

        for (Integer key : keySet) {
            int cnt = map.get(key).cnt;
            while (cnt-- > 0) {
                sb.append(key + " ");
            }
        }
        System.out.println(sb);
    }
}
