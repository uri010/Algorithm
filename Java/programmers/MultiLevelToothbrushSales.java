package programmers;

import java.util.*;

public class MultiLevelToothbrushSales {

    static HashMap<String, Integer> cost = new HashMap<String, Integer>();
    static HashMap<String, String> par = new HashMap<String, String>();

    static void share(String node, int sales) {
        int nextSales = sales / 10;
        cost.replace(node, cost.getOrDefault(node, 0) + sales - nextSales);

        if (nextSales > 0 && par.containsKey(node)) {
            share(par.get(node), nextSales);
        }
    }

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        for (int i = 0; i < enroll.length; i++) {
            cost.put(enroll[i], 0);
            if (referral[i].equals("-")) {
                continue;
            }
            par.put(enroll[i], referral[i]);
        }
        for (int i = 0; i < seller.length; i++) {
            share(seller[i], amount[i] * 100);
        }
        for (int i = 0; i < enroll.length; i++) {
            answer[i] = cost.get(enroll[i]);
        }
        return answer;
    }
}