import java.util.Arrays;
import java.util.Collections;

class Solution {

    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Integer[] arr = new Integer[10000002];
        Arrays.fill(arr, 0);

        for (int i = 0; i < tangerine.length; i++) {
            arr[tangerine[i]]++;
        }

        Arrays.sort(arr, Collections.reverseOrder());

        for (int i = 0; i < 10000001; i++) {
            if (k == 0) {
                return answer;
            }
            if (arr[i] > k) {
                return answer + 1;
            } else if (arr[i] <= k) {
                k -= arr[i];
                answer++;
            }
        }

        return answer;
    }
}