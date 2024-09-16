//
// Created by 김유리 on 2024. 9. 16..
//
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second

int paintCnt, maxWidth;
int n, m;
int board[501][501];
bool visited[501][501];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                queue<pair<int, int> > q;
                visited[i][j] = true;
                q.push(make_pair(i, j));
                int cnt = 0;
                paintCnt++;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    cnt++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visited[nx][ny] || board[nx][ny] != 1) continue;
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
                if (cnt > maxWidth) maxWidth = cnt;
            }
        }
    }
    cout << paintCnt << "\n" << maxWidth;
}
