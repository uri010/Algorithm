package baekjoon;

import java.io.*;

public class Baekjoon_10988 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char str[] = br.readLine().toCharArray();

        int left = 0;
        int right = str.length - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                System.out.println(0);
                return;
            }
            left++;
            right--;
        }
        System.out.println(1);
    }
}
