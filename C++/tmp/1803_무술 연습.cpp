//
// Created by 김유리 on 2022/07/26.
//
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int m, n;
int map[50002][2];
int result[50002][2];
int in_degree[50002][2];
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int line = q.front().first;
        int now = q.front().second;
        q.pop();
        if (result[now][line] != -1) continue;
        result[now][line] = 1;
        int next = map[now][line];
        result[next][!line] = 0;
        in_degree[map[next][!line]][line]--;
        if (in_degree[map[next][!line]][line] == 0) {
            q.push({line, map[next][!line]});
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    memset(result, -1, sizeof(result));

    for (int i = 1; i <= m; i++) {
        cin >> map[i][0];
        in_degree[map[i][0]][1]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> map[i][1];
        in_degree[map[i][1]][0]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i][0] == 0)
            q.push({0, i});
        if (in_degree[i][1] == 0)
            q.push({1, i});
    }
    bfs();

    for (int i = 1; i <= m; i++) {
        if (result[i][0] == -1) {
            q.push({0, i});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (result[i][1] == -1) {
            q.push({1, i});
        }
    }
    bfs();

    for (int i = 1; i <= m; i++) {
        cout << result[i][0];
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << result[i][1];
    }
}