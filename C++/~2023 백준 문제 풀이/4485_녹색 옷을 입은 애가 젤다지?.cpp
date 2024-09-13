//
// Created by 김유리 on 2023/10/10.
//
#include <iostream>
#include <string.h>
#include <queue>

#define INF 1000000000
using namespace std;

int N, cnt;
int cave[125][125];
int dp[125][125];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void BFS() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-cave[0][0], {0, 0}});
    dp[0][0] = cave[0][0];

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if (cost > dp[i][j]) continue;
        dp[i][j] = cost;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= N || nj >= N) continue;
            int next_cost = cost + cave[ni][nj];
            if (next_cost >= dp[ni][nj]) continue;
            dp[ni][nj] = next_cost;
            pq.push({-next_cost, {ni, nj}});
        }

    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    while (cin >> N) {
        cnt++;
        if (N == 0) return 0;
        memset(cave, 0, sizeof(cave));
        for (int i = 0; i < 125; i++) {
            for (int j = 0; j < 125; j++) {
                dp[i][j] = INF;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
            }
        }
        BFS();
        cout << "Problem " << cnt << ": " << dp[N - 1][N - 1] << "\n";
    }
}