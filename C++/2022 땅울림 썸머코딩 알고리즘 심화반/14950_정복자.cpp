//
// Created by 김유리 on 2022/08/02.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, t;
int a, b, c;

int par[10002];
vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t;
    edge.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    int cnt = 0;
    int sum = 0;

    for (auto x: edge[1]) {
        pq.push({-x.second, {1, x.first}});
    }
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        int ni = Find(i);
        int nj = Find(j);
        if (ni == nj) continue;
        if (ni != nj) {
            par[nj] = ni;
            sum += cost + (t * cnt);
            cnt++;
            if (cnt == n - 1) break;
        }

        for (auto x: edge[j]) {
            pq.push({-x.second, {j, x.first}});
        }
    }
    cout << sum;
}