package programmers;

import java.util.*;

public class OvertimeIndex {

    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return -Integer.compare(o1, o2);
            }
        });
        for (int i = 0; i < works.length; i++) {
            maxHeap.add(works[i]);
        }

        while (n > 0) {
            int num = maxHeap.poll();
            if (num == 0) {
                return 0;
            }

            num--;
            maxHeap.add(num);
            n--;
        }
        while (!maxHeap.isEmpty()) {
            int num = maxHeap.poll();
            answer += num * num;
        }
        return answer;
    }
}
