//
// Created by 김유리 on 2023/08/04.
//
#include <iostream>

using namespace std;

int N, K;
int arr[101];
int dp[10010];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= K; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    cout << dp[K];
}