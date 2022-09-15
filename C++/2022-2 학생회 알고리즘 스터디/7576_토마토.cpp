//
// Created by 김유리 on 2022/09/15.
//
#include <iostream>
#include <queue>

using namespace std;

int m, n;
int ans;
queue<pair<int, pair<int, int>>> q;
int tomato[1001][1001];
bool visited[1001][1001];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void BFS() {
    while (!q.empty()) {
        int cnt = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        ans = max(ans, cnt);
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (!visited[ni][nj] && tomato[ni][nj] == 0) {
                tomato[ni][nj] = 1;
                visited[ni][nj] = true;
                q.push({cnt + 1, {ni, nj}});
            }
        }
    }
}

bool checkAll() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j])
                return false;
        }
    }
    return true;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == -1)
                visited[i][j] = true;
            else if (tomato[i][j] == 1) {
                visited[i][j] = true;
                q.push({0, {i, j}});
            }
        }
    }
    if (checkAll()) {
        cout << 0;
        return 0;
    }

    BFS();
    if (checkAll()) cout << ans;
    else cout << -1;
}