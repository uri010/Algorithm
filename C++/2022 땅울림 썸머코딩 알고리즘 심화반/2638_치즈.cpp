//
// Created by 김유리 on 2022/08/04.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[102][102];
int tmp[102][102];
int da[4] = {1, -1, 0, 0};
int db[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
bool visited[102][102];

void BFS(int a, int b) {
    memset(tmp, 0, sizeof(tmp));
    memset(visited, false, sizeof(visited));
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty()) {
        a = q.front().first;
        b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + da[i];
            int nb = b + db[i];
            if (na <= 0 || nb <= 0 || na > n || nb > m || visited[na][nb]) continue;
            if (map[na][nb] == 0) {
                visited[na][nb] = true;
                q.push({na, nb});
            }
        }
    }
}

void setBlank() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j]) tmp[i][j] = 0;
            else tmp[i][j] = 1;
        }
    }
}

void findBlank() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 0) {
                BFS(i, j);
                setBlank();
                return;
            }
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                total++;
            }
        }
    }

    int cnt = 0;
    int time = 0;
    while (cnt < total) {
        findBlank();
        time++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (tmp[i][j] == 1) {
                    int contact = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + da[k];
                        int nj = j + db[k];
                        if (ni <= 0 || nj <= 0 || ni > n || nj > m) continue;
                        if (tmp[ni][nj] == 0) contact++;
                    }
                    if (contact >= 2) {
                        map[i][j] = 0;
                        cnt++;
                    }
                }
            }
        }
    }
    cout << time;


}