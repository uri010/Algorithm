//
// Created by 김유리 on 2022/07/30.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m, x, y;
int ans, cnt = 1;
int cost[1002][1002];
int par[1002];
vector<pair<int, int>> result;
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int a) {
    if (a == par[a])
        return a;

    return par[a] = Find(par[a]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x = Find(x);
        y = Find(y);

        if (x != y) {
            par[y] = x;
            cnt++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if (i == 1 || j == 1 || i == j) continue;
            pq.push({-cost[i][j], {i, j}});
        }
    }

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        if (cnt == n) break;

        int ni = Find(i);
        int nj = Find(j);
        if (ni != nj) {
            ans += now_cost;
            result.push_back({i, j});
            par[nj] = ni;
            cnt++;
        }
    }
    cout << ans << " " << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << "\n";
    }

}