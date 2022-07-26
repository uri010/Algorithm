//
// Created by 김유리 on 2022/07/18.
//
#include <iostream>

using namespace std;

int dp[11][1001];
int n;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[j][i] += dp[k][i - 1] % 10007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[i][n] % 10007;
    }
    cout << ans % 10007;
}