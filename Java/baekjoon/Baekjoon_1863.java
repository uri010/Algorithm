package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Baekjoon_1863 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String input[];
        int arr[] = new int[1000001];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            arr[i] = Integer.parseInt(input[1]);
        }

        Stack<Integer> stack = new Stack<>();
        stack.push(0);

        for (int i = 0; i < n; i++) {
            if (stack.peek() < arr[i]) {
                cnt++;
                stack.push(arr[i]);
            } else {
                while (!stack.isEmpty() && stack.peek() > arr[i]) {
                    stack.pop();
                }

                if (stack.peek() == arr[i]) {
                    continue;
                } else if (stack.peek() < arr[i]) {
                    stack.push(arr[i]);
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}
