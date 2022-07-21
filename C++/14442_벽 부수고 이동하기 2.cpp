//
// Created by 김유리 on 2022/07/20.
//
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, k;
int map[1001][1001];
int dist[1001][1001][11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, pair<int, int>>> q;

void BFS() {
    while (!q.empty()) {
        int cnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (y == n && x == m) {
            cout << dist[y][x][cnt];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int to_y = y + dy[i];
            int to_x = x + dx[i];
            if (to_x < 1 || to_y < 1 || to_x > m || to_y > n) continue;
            int tmp = cnt + map[to_y][to_x];
            if (tmp > k) continue;
            if (dist[to_y][to_x][tmp] != 0) {
                if (dist[to_y][to_x][tmp] <= dist[y][x][cnt] + 1)
                    continue;
            }
            dist[to_y][to_x][tmp] = dist[y][x][cnt] + 1;
            q.push({tmp, {to_y, to_x}});
        }
    }
    cout << -1;
    return;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1] - '0';
        }
    }

    dist[1][1][0] = 1;
    q.push({0, {1, 1}});
    BFS();
}