//
// Created by 김유리 on 2022/08/02.
//
#include <iostream>
#include <cstring>
#include <queue>

#define INF 100000000
using namespace std;

int t, n, m, k;
int u, v, c, d;
int dist[102][10002];
vector<vector<pair<int, pair<int, int>>>> edge;
priority_queue<pair<pair<int, int>, int>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        while (!pq.empty()) {
            pq.pop();
        }
        cin >> n >> m >> k;
        edge.clear();
        edge.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dist[i][j] = INF;
            }
        }

        for (int i = 0; i < k; i++) {
            cin >> u >> v >> c >> d;
            edge[u].push_back({v, {c, d}});
        }

        dist[1][0] = 0;
        pq.push({{0, 0}, 1});
        pair<int, int> result;
        while (!pq.empty()) {
            int time = -pq.top().first.first;
            int cost = pq.top().first.second;
            int now = pq.top().second;
            pq.pop();

            if (dist[now][cost] < time) continue;
            if (now == n) {
                result = {now, cost};
                break;
            }

            for (auto x: edge[now]) {
                int next = x.first;
                int next_cost = x.second.first + cost;
                int next_time = x.second.second + time;

                if (next_cost > m) continue;
                if (dist[next][next_cost] <= next_time) continue;
                dist[next][next_cost] = next_time;
                pq.push({{-next_time, next_cost}, next});
            }
        }

        if (result.first != 0 && result.second != 0 && dist[result.first][result.second] != INF)
            cout << dist[result.first][result.second] << "\n";
        else cout << "Poor KCM" << "\n";
    }
}