package programmers;

import java.util.*;
import java.lang.*;

public class MineMineral {

    public static class Node {

        int stone;
        int iron;
        int dia;

        Node(int stone, int iron, int dia) {
            this.stone = stone;
            this.iron = iron;
            this.dia = dia;
        }

    }


    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        List<Node> li = new ArrayList();
        int totalPicks = picks[0] + picks[1] + picks[2];
        int size = minerals.length;
        if (minerals.length > totalPicks * 5) {
            size = totalPicks * 5;
        }

        int diaFigure = 0;
        int ironFigure = 0;
        int stoneFigure = 0;
        for (int i = 0; i < size; i++) {
            if (minerals[i].equals("diamond")) {
                diaFigure += 1;
                ironFigure += 5;
                stoneFigure += 25;
            } else if (minerals[i].equals("iron")) {
                diaFigure += 1;
                ironFigure += 1;
                stoneFigure += 5;
            } else {
                diaFigure += 1;
                ironFigure += 1;
                stoneFigure += 1;
            }

            if (i % 5 == 4 || i == size - 1) {
                li.add(new Node(stoneFigure, ironFigure, diaFigure));
                diaFigure = 0;
                ironFigure = 0;
                stoneFigure = 0;
            }
        }

        //내림차순
        Collections.sort(li, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.stone < o2.stone) {
                    return 1;
                } else if (o1.stone > o2.stone) {
                    return -1;
                } else {
                    if (o1.iron < o2.iron) {
                        return 1;
                    } else if (o1.iron > o2.iron) {
                        return -1;
                    } else {
                        if (o1.dia < o2.dia) {
                            return 1;
                        } else if (o1.dia > o2.dia) {
                            return -1;
                        }
                    }
                }
                return -1;
            }
        });

        for (int i = 0; i < li.size(); i++) {
            Node cur = li.get(i);
            if (picks[0] > 0) {
                picks[0]--;
                answer += cur.dia;
            } else if (picks[1] > 0) {
                picks[1]--;
                answer += cur.iron;
            } else if (picks[2] > 0) {
                picks[2]--;
                answer += cur.stone;
            }
        }
        return answer;
    }
}

