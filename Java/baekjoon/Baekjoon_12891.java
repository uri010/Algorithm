package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_12891 {

    static int myArr[];
    static int checkArr[];
    static int checkSecret;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int s = Integer.parseInt(input[0]);
        int p = Integer.parseInt(input[1]);
        int result = 0;
        checkArr = new int[4];
        myArr = new int[4];
        char arr[] = br.readLine().toCharArray();
        checkSecret = 0;

        String[] acgt = br.readLine().split(" ");
        for (int i = 0; i < acgt.length; i++) {
            checkArr[i] = Integer.parseInt(acgt[i]);
            if (checkArr[i] == 0) {
                checkSecret++;
            }
        }

        for (int i = 0; i < p; i++) { // 문자열 처음 받을 때 세팅
            Add(arr[i]);
        }
        if (checkSecret == 4) {
            result++;
        }

        // 슬라이딩 윈도우
        for (int i = p; i < s; i++) {
            int j = i - p;
            Add(arr[i]);
            Remove(arr[j]);
            if (checkSecret == 4) {
                result++;
            }
        }
        System.out.println(result);
    }

    private static void Remove(char c) {
        switch (c) {
            case 'A':
                if (myArr[0] == checkArr[0]) {
                    checkSecret--;
                }
                myArr[0]--;
                break;
            case 'C':
                if (myArr[1] == checkArr[1]) {
                    checkSecret--;
                }
                myArr[1]--;
                break;
            case 'G':
                if (myArr[2] == checkArr[2]) {
                    checkSecret--;
                }
                myArr[2]--;
                break;
            case 'T':
                if (myArr[3] == checkArr[3]) {
                    checkSecret--;
                }
                myArr[3]--;
                break;

        }
    }

    private static void Add(char c) {
        switch (c) {
            case 'A':
                myArr[0]++;
                if (myArr[0] == checkArr[0]) {
                    checkSecret++;
                }
                break;
            case 'C':
                myArr[1]++;
                if (myArr[1] == checkArr[1]) {
                    checkSecret++;
                }
                break;
            case 'G':
                myArr[2]++;
                if (myArr[2] == checkArr[2]) {
                    checkSecret++;
                }
                break;
            case 'T':
                myArr[3]++;
                if (myArr[3] == checkArr[3]) {
                    checkSecret++;
                }
                break;

        }
    }

}
