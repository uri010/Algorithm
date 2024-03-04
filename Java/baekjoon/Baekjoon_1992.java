package baekjoon;

import java.io.*;

public class Baekjoon_1992 {

    static char s[][];
    static StringBuilder sb = new StringBuilder();

    static void Compression(int x, int y, int size) {
        char type = s[y][x];
        for (int i = y; i < y + size; i++) {
            for (int j = x; j < x + size; j++) {
                if (type != s[i][j]) {
                    size /= 2;
                    sb.append("(");
                    Compression(x, y, size);
                    Compression(x + size, y, size);
                    Compression(x, y + size, size);
                    Compression(x + size, y + size, size);
                    sb.append(")");
                    return;
                }
            }
        }
        sb.append(type);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        s = new char[N][N];
        for (int i = 0; i < N; i++) {
            char[] input = br.readLine().toCharArray();
            for (int j = 0; j < input.length; j++) {
                s[i][j] = input[j];
            }
        }
        Compression(0, 0, N);
        System.out.println(sb);
    }
}
