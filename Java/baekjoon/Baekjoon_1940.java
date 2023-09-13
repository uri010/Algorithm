package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Baekjoon_1940 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int arr[] = new int[N];
        String str[] = br.readLine().split(" ");

        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(arr);

        int i = 0;
        int j = N - 1;
        int count = 0;

        while (i < j) {
            if (arr[i] + arr[j] > M) {
                j--;
            } else if (arr[i] + arr[j] < M) {
                i++;
            } else {
                i++;
                j--;
                count++;
            }
        }
        System.out.println(count);
    }
}
