package programmers;

import java.util.*;

public class DefenseGame {

    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        if (enemy.length == k) {
            return enemy.length;
        }

        for (int i = 0; i < enemy.length; i++) {
            if (n < enemy[i] && k == 0) {
                break;
            }

            pq.add(enemy[i]);
            n -= enemy[i];
            answer++;

            while (n < 0 && !pq.isEmpty()) {
                if (k == 0) {
                    answer--;
                    break;
                }
                n += pq.peek();
                pq.poll();
                k--;
            }
        }
        return answer;
    }
}