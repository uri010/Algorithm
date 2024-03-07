package baekjoon;

import java.io.*;

public class Baekjoon_4659 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String input = br.readLine();
        while (!input.equals("end")) {
            char str[] = input.toCharArray();

            char prev = ' ';
            int coCnt = 0;
            int voCnt = 0;

            boolean isVowel = false;
            boolean isThree = false;
            boolean isTwo = false;
            for (int i = 0; i < str.length; i++) {
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'
                    || str[i] == 'u') {
                    isVowel = true;
                    coCnt = 0;
                    if (++voCnt == 3) {
                        isThree = true;
                        break;
                    }
                    if (prev != ' ' && prev == str[i]) {
                        if (prev != 'e' && prev != 'o') {
                            isTwo = true;
                            break;
                        }
                    }
                } else {
                    voCnt = 0;
                    if (++coCnt == 3) {
                        isThree = true;
                        break;
                    }
                    if (prev != ' ' && prev == str[i]) {
                        isTwo = true;
                        break;
                    }
                }
                prev = str[i];
            }

            if (!isVowel || isThree || isTwo) {
                sb.append("<" + input + "> is not acceptable.\n");
            } else {
                sb.append("<" + input + "> is acceptable.\n");
            }

            input = br.readLine();
        }
        System.out.println(sb);
    }
}
