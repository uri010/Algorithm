package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Baekjoon_1874 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        int num = 1;
        int flag = 0;
        StringBuffer bf = new StringBuffer();

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= num) {
                while (arr[i] >= num) {
                    s.push(num++);
                    bf.append("+\n");
                }
                s.pop();
                bf.append("-\n");
            } else {
                if (arr[i] < s.pop()) {
                    System.out.println("NO");
                    flag = 1;
                    break;
                }
                bf.append("-\n");
            }
        }
        if( flag== 0) System.out.println(bf);
    }

}
