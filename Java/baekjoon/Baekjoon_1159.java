package baekjoon;

import java.io.*;

public class Baekjoon_1159 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int alphabet[] = new int [27];
        for(int i=0; i < N; i++){
            String firstName = br.readLine();
            alphabet[firstName.charAt(0)-'a']++;
        }

        boolean flag = false;
        for(int i=0; i < 27; i++){
            if( alphabet[i] >= 5) {
                sb.append((char)(i+'a'));
                flag = true;
            }
        }
        if( !flag) sb.append("PREDAJA");
        System.out.println(sb);
    }

}
