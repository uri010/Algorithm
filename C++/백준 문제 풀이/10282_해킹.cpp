//
// Created by 김유리 on 2023/08/17.
//
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#define INF 2100000000

using namespace std;

int t, n, d, c, a, b, s;
int cnt, timeAns;
vector<pair<int, int>> edge[10001];
int dp[10001];

void Init() {
    cnt = 0;
    timeAns = 0;
    for (int i = 1; i <= 10000; i++) {
        edge[i].clear();
        dp[i] = INF;
    }
}

void Input() {
    cin >> n >> d >> c;
    for (int i = 0; i < d; i++) {
        cin >> a >> b >> s;
        edge[b].push_back({a, s});
    }
}

void Solve() {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, c);
    dp[c] = 0;

    while (!pq.empty()) {
        int nowTime = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dp[now] < nowTime) continue;

        for (int i = 0; i < edge[now].size(); i++) {
            int nextTime = nowTime + edge[now][i].second;
            int next = edge[now][i].first;

            if (nextTime < dp[next]) {
                dp[next] = nextTime;
                pq.emplace(-nextTime, next);
            }
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        Init();
        Input();
        Solve();

        for (int i = 1; i <= n; i++) {
            if (dp[i] != INF) {
                cnt++;
                timeAns = max(timeAns, dp[i]);
            }
        }
        cout << cnt << " " << timeAns << "\n";
    }
}