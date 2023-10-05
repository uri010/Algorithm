package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1244 {

    static int N, M;
    static int[] switches;

    static void Male(int num) {
        for (int i = num; i <= N; i += num) {
            switches[i] = (switches[i] + 1) % 2;
        }
    }

    static void Female(int num) {
        int left = num - 1;
        int right = num + 1;

        switches[num] = (switches[num] + 1) % 2;
        while (left >= 1 && right <= N) {
            if (switches[left] != switches[right]) {
                break;
            }
            switches[left] = (switches[left] + 1) % 2;
            switches[right] = (switches[right] + 1) % 2;
            left--;
            right++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        switches = new int[N + 1];

        String input[] = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            switches[i] = Integer.parseInt(input[i - 1]);
        }

        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            String student[] = br.readLine().split(" ");
            if (Integer.parseInt(student[0]) == 1) {
                Male(Integer.parseInt(student[1]));
            } else {
                Female(Integer.parseInt(student[1]));
            }
        }

        for (int i = 1; i <= N; i++) {
            System.out.print(switches[i] + " ");
            if (i % 20 == 0) {
                System.out.println();
            }
        }
    }

}
