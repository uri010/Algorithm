//
// Created by 김유리 on 2022/07/22.
//
#include <iostream>
#include <queue>

#define INF 1000000000
using namespace std;

int n;
int map[2224][2224];
int dist[2224][2224];
priority_queue<pair<int, pair<int, int>>> q;
int min_cost = INF;

void solve(int i, int j, int ni, int nj, int cost) {
    if (map[i][j] > map[ni][nj]) {
        if (dist[ni][nj] <= cost) return;
        dist[ni][nj] = cost;
        q.push({-cost, {ni, nj}});
    } else {
        int tmp = map[ni][nj] - map[i][j] + 1;
        if (dist[ni][nj] <= cost + tmp) return;
        dist[ni][nj] = cost+tmp;
        q.push({-(cost + tmp), {ni, nj}});
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            dist[i][j] = INF;
        }
    }
    dist[1][1] = 0;

    q.push({0, {1, 1}});
    while (!q.empty()) {
        int cost = -q.top().first;
        int i = q.top().second.first;
        int j = q.top().second.second;
        q.pop();

        if (cost > dist[i][j]) continue;
        if (1 <= i && i < n && 1 <= j && j < n) {
            solve(i, j, i, j + 1, cost);
            solve(i, j, i + 1, j, cost);
        } else if (i == n && 1 <= j && j < n) {
            solve(i, j, i, j + 1, cost);
        } else if (j == n && 1 <= i && i < n) {
            solve(i, j, i + 1, j, cost);
        } else if (i == n && j == n) {
            continue;
        }

    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dist[n][n];
}
