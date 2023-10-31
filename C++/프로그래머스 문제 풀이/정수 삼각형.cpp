//
// Created by 김유리 on 2023/10/31.
//
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = 0; i < triangle.size(); i++) {
        if (i == 0) {
            dp[i][0] = triangle[i][0];
        } else {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
        answer = max(dp[triangle.size() - 1][i], answer);
    }
    return answer;
}