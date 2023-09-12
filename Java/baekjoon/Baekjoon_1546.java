package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Baekjoon_1546 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Double maxGrade = 0.0;
        Double sum = 0.0;
        String nums[] = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(nums[i]);
            sum += num;
            maxGrade = Math.max(num, maxGrade);
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Double.toString(sum / maxGrade * 100 / N));
        bw.flush();
        bw.close();
    }
}
