package programmers;

public class IntegerTriangle {

    public int solution(int[][] triangle) {
        int answer = 0;
        int size = triangle.length;
        int dp[][] = new int[size + 1][size + 1];
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                dp[0][0] = triangle[0][0];
            } else {
                for (int j = 0; j < triangle[i].length; j++) {
                    if (j == 0) {
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    } else if (j == triangle[i].length - 1) {
                        dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < triangle[size - 1].length; i++) {
            answer = Math.max(answer, dp[size - 1][i]);
        }
        return answer;
    }
}