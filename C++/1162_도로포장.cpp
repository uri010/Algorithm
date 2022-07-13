//
// Created by 김유리 on 2022/07/13.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INF 90000000000
using namespace std;

int n, m, k;
long long dist[10002][21];
vector<vector<pair<int, int>>> edge;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dist[i][j] = INF;
        }
    }
    int a, b, c;
    edge.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    priority_queue<pair<long long, pair<int, int>>> pq; //거리, 정점, 포장개수
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        long long weight = -pq.top().first;
        int vertex = pq.top().second.first;
        int packed = pq.top().second.second;
        pq.pop();
        if (vertex == n) break;
        if (weight > dist[vertex][packed]) continue;

        for (auto e: edge[vertex]) {
            int next = e.first;
            long long cost;
            if (packed < k) {
                cost = 0;
                if (dist[next][packed + 1] > weight + cost) {
                    dist[next][packed + 1] = weight + cost;
                    pq.push({-(weight + cost), {next, packed + 1}});
                }
            }
            cost = e.second;
            if (dist[next][packed] > weight + cost) {
                dist[next][packed] = weight + cost;
                pq.push({-(weight + cost), {next, packed}});
            }
        }
    }
    long long min_cost = INF;
    for (int i = 0; i <= k; i++) {
        if (min_cost > dist[n][i]) min_cost = dist[n][i];
    }
    cout << min_cost;
}