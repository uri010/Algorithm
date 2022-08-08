//
// Created by 김유리 on 2022/08/07.
//
#include <iostream>
#include <queue>
#include <vector>

#define INF 100000000
using namespace std;


int V, E, u, v, w;
int start;
int dist[10002];
vector<int> yogurt;
vector<vector<pair<int, int>>> edge;
vector<int> route;
priority_queue<pair<int, int>> pq;

void solve(int s) {
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    yogurt[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;

        pq.pop();
        if (yogurt[here] < cost) continue;
        for (int i = 0; i < edge[here].size(); ++i) {
            int next = edge[here][i].second;
            int nextcost = edge[here][i].first;

            if (yogurt[next] > yogurt[here] + nextcost) {
                yogurt[next] = yogurt[here] + nextcost;
                pq.push(make_pair(yogurt[next], next));
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> V >> E;
    edge.resize(V + 2);
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        yogurt[i] = INF;
    }
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    for (int i = 0; i < 10; i++) {
        cin >> u;
        route.push_back(u);
    }

    cin >> start;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;
        for (auto x: edge[now]) {
            int next = x.first;
            int next_cost = x.second + cost;
            if (next_cost >= dist[next]) continue;
            dist[next] = next_cost;
            pq.push({-next_cost, next});
        }
    }

    int ans = -1;
    if (start == route[0]) {
        ans = start;
    }
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        fill(yogurt.begin(), yogurt.end(), INF);
        solve(route[i]);
        while (yogurt[route[i]] >= INF) {
            i++;
            if (i > 9)
                break;
        }
        if (i > 9)
            break;
        if (yogurt[route[i]] < INF && route[i] < ans && sum + yogurt[route[i]] >= dist[route[i]])
            ans = route[i];
        if (yogurt[route[i]] < INF)
            sum += yogurt[route[i]];
    }
    cout << ans;
}