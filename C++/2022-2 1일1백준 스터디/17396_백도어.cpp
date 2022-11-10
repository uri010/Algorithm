//
// Created by 김유리 on 2022/11/10.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 10000000000

int n, m, a, b, t;
bool sight[100001];
vector<vector<pair<int, int>>> edge(100001);
long long dist[100001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sight[i];
        if (i == n - 1) sight[i] = false;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        edge[a].push_back({b, t});
        edge[b].push_back({a, t});
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int now = pq.top().second;
        long long time = -pq.top().first;
        pq.pop();

        if (dist[now] < time) continue;
        dist[now] = time;

        for (auto x: edge[now]) {
            long long next_time = time + x.second;
            int next = x.first;
            if (sight[next]) continue;
            if (dist[next] <= next_time) continue;
            dist[next] = next_time;
            pq.push({-next_time, next});
        }
    }
    if (dist[n - 1] == INF) cout << -1 << "\n";
    else cout << dist[n - 1] << "\n";

}