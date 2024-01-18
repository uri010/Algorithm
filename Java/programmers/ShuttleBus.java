package programmers;

import java.util.*;

public class ShuttleBus {

    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (String table : timetable) {
            int time =
                Integer.parseInt(table.substring(0, 2)) * 60 + Integer.parseInt(table.substring(3));
            pq.add(time);
        }

        int busTime = 9 * 60;
        int ttime = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (!pq.isEmpty() && cnt < m) {
                ttime = pq.peek();
                if (ttime <= busTime) {
                    pq.poll();
                    cnt++;
                } else {
                    break;
                }
            }
            if (i == n - 1) {
                if (cnt < m) {
                    String hour = String.format("%02d", busTime / 60);
                    String minute = String.format("%02d", busTime % 60);
                    answer = hour + ":" + minute;
                } else {
                    ttime -= 1;
                    String hour = String.format("%02d", ttime / 60);
                    String minute = String.format("%02d", ttime % 60);
                    answer = hour + ":" + minute;
                }
            }
            busTime += t;

        }
        return answer;
    }
}