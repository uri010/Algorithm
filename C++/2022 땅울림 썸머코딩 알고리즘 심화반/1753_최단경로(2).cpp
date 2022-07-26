//
// Created by 김유리 on 2022/07/13.
//
#include <iostream>
#include <queue>

using namespace std;
#define INF 100000000

int dist[20002], v, e, k;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> v >> e >> k;

    vector<vector<pair<int, int>>> edge(v+1);
    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
    dist[k] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({0, k});

    while (!pq.empty()) {
        int weight = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (weight > dist[vertex])
            continue;

        for (auto u: edge[vertex]) {
            int n = u.first;
            int w = u.second + weight;
            if (dist[n] <= w) continue;
            pq.push({-w, n});
            dist[n] = w;
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}