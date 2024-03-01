package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_3986 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int answer = 0;
        for (int i = 0; i < N; i++) {
            char str[] = br.readLine().toCharArray();
            Stack<String> s = new Stack<>();
            for (int j = 0; j < str.length; j++) {
                if (s.isEmpty()) {
                    s.add(String.valueOf(str[j]));
                } else if (s.peek().equals(String.valueOf(str[j]))) {
                    s.pop();
                } else {
                    s.add(String.valueOf(str[j]));
                }
            }
            if (s.isEmpty()) {
                answer++;
            }
        }
        System.out.println(answer);
    }
}
