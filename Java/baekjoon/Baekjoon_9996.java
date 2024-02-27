package baekjoon;

import java.io.*;
import java.util.*;

public class Baekjoon_9996 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        List<String> patterns = new ArrayList<>();
        int patternSize = 0;

        char p[] = br.readLine().toCharArray();
        String tmp = "";
        for (int i = 0; i < p.length; i++) {
            if (p[i] == '*') {
                patterns.add(tmp);
                tmp = "";
            } else {
                tmp += p[i];
                patternSize++;
            }
        }
        if (!tmp.equals("")) {
            patterns.add(tmp);
        }

        for (int i = 0; i < N; i++) {
            char str[] = br.readLine().toCharArray();

            if (str.length < patternSize) {
                sb.append("NE\n");
                continue;
            }

            boolean isFirst = true;
            char pattern[] = patterns.get(0).toCharArray();
            for (int j = 0; j < pattern.length; j++) {
                if (pattern[j] != str[j]) {
                    isFirst = false;
                    sb.append("NE\n");
                    break;
                }
            }
            if (!isFirst) {
                continue;
            }

            boolean isLast = true;
            pattern = patterns.get(patterns.size() - 1).toCharArray();
            for (int j = 0; j < pattern.length; j++) {
                if (pattern[j] != str[str.length - pattern.length + j]) {
                    isLast = false;
                    sb.append("NE\n");
                    break;
                }
            }
            if (!isLast) {
                continue;
            }

            if (patterns.size() == 2) {
                sb.append("DA\n");
                continue;
            }

            int patternIdx = 1;
            for (int j = patterns.get(0).length();
                j < str.length - patterns.get(patterns.size()-1).length(); j++) {
                if (str[j] == patterns.get(patternIdx).charAt(0)) {
                    boolean isSame = true;
                    for (int k = 0; k < patterns.get(patternIdx).length(); k++) {
                        if (str[j + k] != patterns.get(patternIdx).charAt(k)) {
                            isSame = false;
                            break;
                        }
                    }
                    if (isSame) {
                        patternIdx++;
                        j += patterns.get(patternIdx).length() - 1;
                    }
                }

                if (patternIdx == patterns.size() - 1) {
                    sb.append("DA\n");
                    break;
                }
            }
        }
        System.out.println(sb);

    }
}
