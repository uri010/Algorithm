//
// Created by 김유리 on 2022/07/16.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> dp;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    dp.resize(n + 2);
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x;
            dp[i].push_back(x);
        }
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dp[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dp[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][2];
    }
    int min_cost = dp[n][0];
    for (int i = 1; i < 3; i++) {
        if (min_cost > dp[n][i]) min_cost = dp[n][i];
    }
    cout << min_cost;
}