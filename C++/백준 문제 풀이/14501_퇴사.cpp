//
// Created by 김유리 on 2023/08/03.
//
#include <iostream>

using namespace std;

int N, T, P;
pair<int, int> arr[20];
int dp[20];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T >> P;
        arr[i] = {T, P};
    }

    int ans = 0;
    for (int i = 1; i <= N+1; i++) {
        dp[i] = max(ans, dp[i]);
        if (arr[i].first + i <= N + 1) {
            dp[arr[i].first + i] = max(dp[arr[i].first + i], arr[i].second + dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}