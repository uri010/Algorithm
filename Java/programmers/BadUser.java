package programmers;

import java.util.*;

public class BadUser {

    static boolean visited[] = new boolean[9];
    static int size;
    static Set<String> set = new HashSet<>();

    static boolean isSame(String a, String b) {
        if (a.length() == b.length()) {
            char[] A = a.toCharArray();
            char[] B = b.toCharArray();
            for (int i = 0; i < A.length; i++) {
                if (A[i] == '*' || A[i] == B[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }

    public static void permutation(String[] banned_id, String[] user_id, String[] resultList,
        int idx) {
        if (idx == size) {
            List<String> tmp = new ArrayList<>();
            String id = "";
            for (int i = 0; i < banned_id.length; i++) {
                if (isSame(banned_id[i], resultList[i])) {
                    tmp.add(resultList[i]);
                }
            }
            if (tmp.size() == banned_id.length) {
                tmp.sort(Comparator.naturalOrder());
                for (int i = 0; i < tmp.size(); i++) {
                    id += tmp.get(i);
                }
                set.add(id);
            }
        }
        for (int i = 0; i < user_id.length; i++) {
            if (visited[i]) {
                continue;
            }

            resultList[idx] = user_id[i];
            visited[i] = true;
            permutation(banned_id, user_id, resultList, idx + 1);
            visited[i] = false;
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        Arrays.sort(user_id);
        size = banned_id.length;

        String resultList[] = new String[9];
        permutation(banned_id, user_id, resultList, 0);
        return set.size();
    }
}