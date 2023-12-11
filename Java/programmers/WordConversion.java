package programmers;

import java.util.*;

public class WordConversion {
    static class Word {

        int index;
        int cnt;

        Word(int index, int cnt) {
            this.index = index;
            this.cnt = cnt;
        }
    }

    static boolean oneCharDiff(String a, String b) {
        int diffCnt = 0;
        char[] arrA = a.toCharArray();
        char[] arrB = b.toCharArray();
        for (int i = 0; i < arrA.length; i++) {
            if (arrA[i] != arrB[i]) {
                diffCnt++;
            }
        }
        if (diffCnt == 1) {
            return true;
        }
        return false;
    }

    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        List<Integer> oneCharDiffBegin = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            if (oneCharDiff(words[i], begin)) {
                oneCharDiffBegin.add(i);
            }
        }

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j) {
                    continue;
                }
                if (oneCharDiff(words[i], words[j])) {
                    graph.get(i).add(j);
                }
            }
        }

        for (int i = 0; i < oneCharDiffBegin.size(); i++) {
            Queue<Word> queue = new LinkedList<>();
            boolean visited[] = new boolean[words.length];
            for (int j = 0; j < words.length; j++) {
                visited[j] = false;
            }
            queue.add(new Word(oneCharDiffBegin.get(i), 1));
            visited[oneCharDiffBegin.get(i)] = true;

            while (!queue.isEmpty()) {
                Word cur = queue.peek();
                queue.poll();

                if (words[cur.index].equals(target)) {
                    if (answer < cur.cnt) {
                        answer = cur.cnt;
                    }
                    break;
                }
                for (int j = 0; j < graph.get(cur.index).size(); j++) {
                    if (!visited[graph.get(cur.index).get(j)]) {
                        visited[graph.get(cur.index).get(j)] = true;
                        queue.add(new Word(graph.get(cur.index).get(j), cur.cnt + 1));
                    }
                }
            }
        }

        return answer;
    }
}
