package baekjoon;

import java.util.Arrays;
import java.util.Scanner;

public class Baekjoon_2750 { // 백준에선 클래스 이름을 Main으로 바꿔야 함

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }
}
