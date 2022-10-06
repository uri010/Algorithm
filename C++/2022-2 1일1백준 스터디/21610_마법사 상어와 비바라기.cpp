//
// Created by 김유리 on 2022/10/06.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, r, c, d, s;
int map[51][51];
bool visited[51][51];
int di[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dj[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int diag_i[4] = {-1, -1, 1, 1};
int diag_j[4] = {-1, 1, -1, 1};
queue<pair<int, int>> cloud;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    cloud.push({n, 1});
    cloud.push({n, 2});
    cloud.push({n - 1, 1});
    cloud.push({n - 1, 2});

    for (int i = 0; i < m; i++) {
        cin >> d >> s;
        int size = cloud.size();
        for (int j = 0; j < size; j++) {
            r = (cloud.front().first + di[d] * s) % n;
            c = (cloud.front().second + dj[d] * s) % n;
            if (r <= 0) {
                r += n;
            }
            if (c <= 0) {
                c += n;
            }
            cloud.pop();
            cloud.push({r, c});
            map[r][c]++;
        }
        while (!cloud.empty()) {
            int cnt = 0;
            r = cloud.front().first;
            c = cloud.front().second;
            cloud.pop();
            for (int k = 0; k < 4; k++) {
                int mr = r + diag_i[k];
                int mc = c + diag_j[k];
                if (mr <= 0 || mc <= 0 || mr > n || mc > n) continue;
                if (map[mr][mc] > 0)
                    cnt++;
            }
            visited[r][c] = true;
            map[r][c] += cnt;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][k] >= 2 && !visited[j][k]) {
                    cloud.push({j, k});
                    map[j][k] -= 2;
                }
            }
        }
        memset(visited, false, sizeof(visited));
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            total += map[i][j];
        }
    }
    cout << total;
}