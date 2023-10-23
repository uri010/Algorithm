package programmers;

public class SumOfSubsequences {

    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        int s = 0, e = 0;
        int subLen = sequence.length + 1;
        int sum = sequence[0];

        while (s <= e && e < sequence.length) {
            if (sum < k) {
                if (++e < sequence.length) {
                    sum += sequence[e];
                }
            } else if (sum > k) {
                sum -= sequence[s++];
            } else {
                if (subLen > e - s + 1) {
                    subLen = e - s + 1;
                    answer[0] = s;
                    answer[1] = e;
                } else if (subLen == e - s + 1 && answer[0] > s) {
                    answer[0] = s;
                    answer[1] = e;
                }
                sum -= sequence[s++];
            }
        }
        return answer;
    }
}
