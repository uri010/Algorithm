package programmers;

public class StringNumberWord {

    public int solution(String s) {
        String answer = new String();
        String numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
            "eight", "nine"};

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) - '0' >= 0 && s.charAt(i) - '0' <= 9) {
                answer += s.charAt(i) - '0';
            } else {
                for (int j = 0; j < 10; j++) {
                    if (numbers[j].charAt(0) == s.charAt(i) && numbers[j].charAt(1) == s.charAt(
                        i + 1)) {
                        answer += Integer.toString(j);
                        i += numbers[j].length() - 1;
                        break;
                    }
                }
            }
        }
        return Integer.parseInt(answer);
    }
}
