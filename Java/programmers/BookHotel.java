package programmers;

import java.util.*;

public class BookHotel {

    public int solution(String[][] book_time) {
        int answer = 1;
        Arrays.sort(book_time, new Comparator<String[]>() {
            @Override
            public int compare(String[] arr1, String[] arr2) {
                String[] split1 = arr1[0].split(":");
                String[] split2 = arr2[0].split(":");
                int time1 = Integer.parseInt(split1[0]) * 60 + Integer.parseInt(split1[1]);
                int time2 = Integer.parseInt(split2[0]) * 60 + Integer.parseInt(split2[1]);
                if (time1 > time2) {
                    return 1;
                } else if (time1 == time2) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });

        List<Integer> used_room = new ArrayList<>();
        used_room.add(0);
        for (String[] bt : book_time) {
            String[] split1 = bt[0].split(":");
            String[] split2 = bt[1].split(":");
            int start_time = Integer.parseInt(split1[0]) * 60 + Integer.parseInt(split1[1]);
            int end_time = Integer.parseInt(split2[0]) * 60 + Integer.parseInt(split2[1]) + 10;
            //빈방이 있는지
            boolean flag = true;
            for (int i = 0; i < used_room.size(); i++) {
                if (used_room.get(i) <= start_time) {
                    used_room.set(i, end_time);
                    flag = false;
                    break;
                }
            }
            //빈 방이 없을 시 새 방 만들기
            if (flag) {
                answer++;
                used_room.add(end_time);
            }
        }
        return answer;
    }
}
