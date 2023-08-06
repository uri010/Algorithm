//
// Created by 김유리 on 2023/08/06.
//
#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int W[101];
int V[101];
int dp[101][100001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        cin >> V[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - W[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];

}