//
// Created by 김유리 on 2024. 9. 16..
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int minCnt;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= m; j++) {
            board[i][j] = str[j - 1]-'0';
        }
    }

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(1, make_pair(1, 1)));
    visited[1][1] = true;

    while (!q.empty()) {
        int cnt = q.front().first;
        pair<int, int> cur = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx == n && ny == m) {
                cout << cnt + 1;
                return 0;
            }
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (visited[nx][ny] || board[nx][ny] != 1) continue;
            visited[nx][ny] = true;
            q.push(make_pair(cnt + 1, make_pair(nx, ny)));
        }
    }
}