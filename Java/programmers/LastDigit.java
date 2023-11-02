package programmers;

import java.util.*;

public class LastDigit {

    class Solution {

        public List solution(int[] numbers) {
            Stack<Integer> s = new Stack<>();
            List<Integer> list = new ArrayList<>();

            s.add(numbers[numbers.length - 1]);
            list.add(-1);

            for (int i = numbers.length - 2; i >= 0; i--) {
                int num = -1;

                while (!s.isEmpty()) {
                    if (s.peek() > numbers[i]) {
                        num = s.peek();
                        break;
                    } else {
                        s.pop();
                    }
                }
                s.add(numbers[i]);
                list.add(num);
            }

            Collections.reverse(list);
            return list;
        }
    }
}
