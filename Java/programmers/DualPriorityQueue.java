package programmers;

import java.util.*;

class DualPriorityQueue {

    static PriorityQueue<Integer> min = new PriorityQueue<>();
    static PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());

    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        for (int i = 0; i < operations.length; i++) {
            String[] ops = operations[i].split(" ");

            if (ops[0].equals("I")) {
                int num = Integer.parseInt(ops[1]);
                min.offer(num);
                max.offer(num);
            } else {
                if (min.size() == 0) {
                    continue;
                }

                int tmp;
                if (ops[1].equals("1")) {
                    tmp = max.poll();
                    min.remove(tmp);
                } else {
                    tmp = min.poll();
                    max.remove(tmp);
                }
            }
        }

        if (min.size() != 0) {
            answer[0] = max.poll();
            answer[1] = min.poll();
        }

        return answer;
    }
}