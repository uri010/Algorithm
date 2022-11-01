//
// Created by 김유리 on 2022/07/16.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int house[1002][3];
int dp[1002][3];


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;

    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x;
            house[i][j] = x;
        }
    }

    int ans = 1000001;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == i)
                dp[1][j] = house[1][j];
            else
                dp[1][j] = 1000001;
        }
        for (int j = 2; j <= n; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + house[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + house[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + house[j][2];
        }
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    cout << ans;
}