package programmers;

public class MagicElevator {

    public int solution(int storey) {
        int answer = 0;
        while (storey >= 0) {
            if (storey == 0) {
                return answer;
            }
            int res = storey % 10;
            if (res > 5) {
                answer += 10 - res;
                storey += 10 - res;
            } else if (res == 5 && (storey / 10) % 10 >= 5) {
                answer += 10 - res;
                storey += 10 - res;
            } else {
                answer += res;
                storey -= res;
            }
            storey /= 10;
        }
        return answer;
    }
}