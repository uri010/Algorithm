//
// Created by 김유리 on 2022/08/05.
//
#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000
using namespace std;

int n, t, m, l;
int a, b, c, d;
int dist[102][10002];
vector<vector<pair<int, pair<int, int>>>> edge;
priority_queue<pair<pair<int, int>, int>> pq; //비용 시간 출발건물 도착건물

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> t >> m >> l;

    edge.resize(n + 2);
    while (l--) {
        cin >> a >> b >> d >> c;
        edge[a].push_back({b, {c, d}});
        edge[b].push_back({a, {c, d}});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10001; j++) {
            dist[i][j] = INF;
        }
    }

    dist[1][0] = 0;
    pq.push({{0, 0}, 1});

    while (!pq.empty()) {
        int cost = -pq.top().first.first;
        int time = pq.top().first.second;
        int now = pq.top().second;
        pq.pop();

        if (dist[now][time] < cost)continue;
        if (now == n) {
            cout << cost;
            return 0;
        }

        for (auto x: edge[now]) {
            int next = x.first;
            int next_time = x.second.second + time;
            int next_cost = x.second.first + cost;
            if (next_time > t) continue;
            if (next_cost > m) continue;
            if (next_cost >= dist[next][next_time]) continue;
            dist[next][next_time] = next_cost;
            pq.push({{-next_cost, next_time}, next});
        }
    }
    cout << -1;
}