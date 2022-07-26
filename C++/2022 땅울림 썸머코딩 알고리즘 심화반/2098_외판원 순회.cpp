//
// Created by 김유리 on 2022/07/12.
//
#include <iostream>
#include <cmath>

using namespace std;
#define MAX 1000000000;

int dp[17][65537];
int w[17][17];
int n;

int solve(int cur, int visit) {
    if (visit == (1 << n) - 1 && w[cur][0])
        return w[cur][0];

    if (dp[cur][visit]) return dp[cur][visit];
    dp[cur][visit] = MAX;

    for (int i = 1; i < n; i++) {
        if (visit & (1 << i)) continue;
        if (!w[cur][i]) continue;
        dp[cur][visit] = min(dp[cur][visit], solve(i, visit | (1 << i)) + w[cur][i]);
    }
    return dp[cur][visit];
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    cout << solve(0, 1);
}