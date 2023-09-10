package baekjoon;

import java.util.Scanner;

public class Baekjoon_11720 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String str = scanner.next();
        char[] arr = str.toCharArray();
        int answer = 0;
        for (char c : arr) {
            answer += (c - 48);
        }
        System.out.println(answer);
    }
}
