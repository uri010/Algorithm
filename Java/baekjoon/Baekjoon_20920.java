package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_20920 {

    static Map<String, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            if (str.length() < M) {
                continue;
            }
            if (!map.containsKey(str)) {
                map.put(str, 0);
            }
            int cnt = map.get(str);
            map.replace(str, cnt + 1);
        }

        List<String> words = new ArrayList<>(map.keySet());

        Collections.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (Integer.compare(map.get(o1), map.get(o2)) != 0) {
                    return Integer.compare(map.get(o2), map.get(o1));
                }
                if (o1.length() != o2.length()) {
                    return o2.length() - o1.length();
                }
                return o1.compareTo(o2);
            }
        });

        StringBuilder sb = new StringBuilder();
        for (String str : words) {
            sb.append(str + "\n");
        }
        System.out.println(sb);
    }
}
