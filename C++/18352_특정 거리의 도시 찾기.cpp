//
// Created by 김유리 on 2022/07/15.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define INF 987654321

int n, m, k, x;
vector<vector<int>> edge;
int dist[300002];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> x;
    edge.resize(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] <= cost) continue;

        for (auto u: edge[now]) {
            int next_cost = 1;

            if (dist[u] <= cost + next_cost) continue;
            dist[u] = cost + next_cost;
            pq.push({-(cost + next_cost), u});
        }
    }
    int flag= 0;
    for(int i=1; i <=n; i++){
        if( dist[i] == k ) {
            cout << i<< "\n";
            flag = 1;
        }
    }
    if( flag == 0 ) cout << -1;

}
