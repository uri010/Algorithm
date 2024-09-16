//
// Created by 김유리 on 2024. 9. 17..
//
#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 1001
using namespace std;

int R, C;
char board[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> J;
queue<pair<int, int>> F;
int fire[MAX][MAX];
int visited[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'J') {
                J.push({i, j});
                visited[i][j] = 1;
            } else if (board[i][j] == 'F') {
                F.push({i, j});
                fire[i][j] = 1;
            }
        }
    }

    // 불 먼저 내기
    while (!F.empty()) {
        pair<int, int> cur = F.front();
        int cnt = fire[cur.first][cur.second];
        F.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire[nx][ny] != 0 || board[nx][ny] == '#') continue;
            fire[nx][ny] = cnt + 1;
            F.push({nx, ny});
        }
    }

    while (!J.empty()) {
        pair<int, int> cur = J.front();
        int cnt = visited[cur.first][cur.second];
        J.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << cnt;
                return 0;
            }

            if (visited[nx][ny] != 0 || board[nx][ny] == '#') continue;
            if (visited[cur.first][cur.second] + 1 >= fire[nx][ny] && fire[nx][ny] > 0) continue;
            visited[nx][ny] = cnt + 1;
            J.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}