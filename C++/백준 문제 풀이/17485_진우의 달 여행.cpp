//
// Created by 김유리 on 2023/08/08.
//
#include <iostream>

#define INF 2100000000
using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001][4];

bool isValid(int i, int j) {
    return i > 0 && i <= N && j > 0 && j <= M;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (i == 1) {
                dp[i][j][1] = arr[i][j];
                dp[i][j][2] = arr[i][j];
                dp[i][j][3] = arr[i][j];
            } else if (j == M)
                dp[i][j][1] = INF;
            else if (j == 1)
                dp[i][j][3] = INF;
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (isValid(i - 1, j + 1))
                dp[i][j][1] = min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]) + arr[i][j];
            if (isValid(i - 1, j))
                dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j][3]) + arr[i][j];
            if (isValid(i - 1, j - 1))
                dp[i][j][3] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
        }
    }
    int ans = INF;
    for (int j = 1; j <= M; j++) {
        for (int k = 1; k <= 3; k++) {
            if (ans > dp[N][j][k]) ans = dp[N][j][k];
        }
    }
    cout << ans;
}