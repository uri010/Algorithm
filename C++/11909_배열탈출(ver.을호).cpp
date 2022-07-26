//
// Created by 김유리 on 2022/07/25.
//
#include <iostream>

using namespace std;

int n, map[2223][2223], dp[2223][2223];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 1; i < n; i++) {
        if (map[i][0] >= map[i - 1][0])
            dp[i][0] = dp[i - 1][0] + map[i][0] - map[i - 1][0] + 1;
        else
            dp[i][0] = dp[i - 1][0];
        if (map[0][i] >= map[0][i - 1])
            dp[0][i] = dp[0][i - 1] + map[0][i] - map[0][i - 1] + 1;
        else
            dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int a = map[i - 1][j] > map[i][j] ? 0 : map[i][j] - map[i - 1][j] + 1;
            int b = map[i][j - 1] > map[i][j] ? 0 : map[i][j] - map[i][j - 1] + 1;
            dp[i][j] = min(dp[i - 1][j] + a, dp[i][j - 1] + b);
        }
    }
    cout << dp[n - 1][n - 1];

}