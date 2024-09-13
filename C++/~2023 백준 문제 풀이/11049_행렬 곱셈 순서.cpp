#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501][501];
int map[501][2];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> map[i][0];
        cin >> map[i][1];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    input();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[j][i + j] = 1000000000;
            for (int k = j; k <= i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + map[j][0] * map[k][1] * map[i + j][1]);
            }
        }
    }
    cout << dp[1][n];
}

