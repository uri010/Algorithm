//
// Created by 김유리 on 2022/08/07.
//
#include <iostream>
#include <queue>
#include <vector>

#define INF 99999999999999
typedef long long ll;
using namespace std;


ll V, E, u, v, w;
ll start;
ll dist[10002];
vector<ll> yogurt;
vector<vector<pair<ll, ll>>> edge;
vector<ll> route(10);
priority_queue<pair<ll, ll>> pq;

void solve(ll s) {
    priority_queue<pair<ll, int>> q;
    q.push({0, s});
    yogurt[s] = 0;

    while (!q.empty()) {
        ll cost = -q.top().first;
        ll now = q.top().second;
        q.pop();

        if (yogurt[now] < cost) continue;
        for (auto x: edge[now]) {
            ll next = x.first;
            ll next_cost = x.second + cost;
            if (yogurt[next] <= next_cost) continue;
            yogurt[next] = next_cost;
            q.push({-next_cost, next});
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
    }
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    for (int i = 0; i < 10; i++) {
        cin >> route[i];
    }
    yogurt.resize(V+2);

    cin >> start;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        ll cost = -pq.top().first;
        ll now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;
        for (auto x: edge[now]) {
            ll next = x.first;
            ll next_cost = x.second + cost;
            if (next_cost >= dist[next]) continue;
            dist[next] = next_cost;
            pq.push({-next_cost, next});
        }
    }

    ll ans = INF;
    if (start == route[0]) {
        ans = start;
    }
    ll sum = 0;
    for (int i = 0; i < 9; i++) {
        fill(yogurt.begin(), yogurt.end(), INF);
        solve(route[i]);
        while (yogurt[route[i + 1]] == INF) {
            i++;
            if (i >= 9)
                break;
        }
        if (i >= 9)
            break;
        if (yogurt[route[i + 1]] < INF && sum + yogurt[route[i + 1]] >= dist[route[i + 1]])
            ans = min(ans, route[i + 1]);
        if (yogurt[route[i + 1]] < INF)
            sum += yogurt[route[i + 1]];
    }
    if (ans == INF) ans = -1;
    cout << ans;
}