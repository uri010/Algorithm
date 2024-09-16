//
// Created by 김유리 on 2024. 9. 16..
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int board[1001][1001];
bool visited[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isAllRipen() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> M >> N;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    if (isAllRipen()) {
        cout << 0;
        return 0;
    }

    int maxCnt = 0;
    while (!q.empty()) {
        int cnt = q.front().first;
        pair<int, int> cur = q.front().second;
        q.pop();
        if (maxCnt < cnt) maxCnt = cnt;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == -1) visited[nx][ny] = true;
            else if (board[nx][ny] == 0) {
                visited[nx][ny] = true;
                board[nx][ny] = 1;
                q.push({cnt + 1, {nx, ny}});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << maxCnt;
}