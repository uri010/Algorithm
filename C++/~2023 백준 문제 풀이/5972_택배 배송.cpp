//
// Created by 김유리 on 2023/08/20.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 2100000000

using namespace std;

int N, M, C, A, B;
vector<vector<pair<int, int>>> edge(50001);
int dp[50001];

void Solve() {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    dp[1] = 0;

    while (!pq.empty()) {
        int curCnt = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dp[cur] < curCnt) continue;

        for (int i = 0; i < edge[cur].size(); i++) {
            int nextCnt = curCnt + edge[cur][i].second;
            int next = edge[cur][i].first;

            if (dp[next] <= nextCnt) continue;
            dp[next] = nextCnt;
            pq.emplace(-nextCnt, next);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    fill(&dp[0], &dp[50001], INF);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }

    Solve();
    cout << dp[N];
}