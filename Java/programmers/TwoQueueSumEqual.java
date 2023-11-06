package programmers;

import java.util.*;

public class TwoQueueSumEqual {

    public int solution(int[] queue1, int[] queue2) {
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();

        long sum1 = 0L;
        long sum2 = 0L;
        for (int i = 0; i < queue1.length; i++) {
            q1.add(queue1[i]);
            sum1 += queue1[i];
            q2.add(queue2[i]);
            sum2 += queue2[i];
        }

        long goal = (sum1 + sum2) / 2;
        int cnt = 0;
        while (cnt <= queue1.length * 2 + 2) {
            cnt++;
            if (sum1 < goal) {
                q1.add(q2.peek());
                sum1 += q2.peek();
                sum2 -= q2.peek();
                q2.poll();
            } else if (sum1 > goal) {
                q2.add(q1.peek());
                sum2 += q1.peek();
                sum1 -= q1.peek();
                q1.poll();
            } else {
                return cnt - 1;
            }
        }
        return -1;
    }
}
