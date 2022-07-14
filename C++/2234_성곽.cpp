//
// Created by 김유리 on 2022/07/13.
//
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[51][51];
bool visited[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;
int max_room;
int remove_max_room;
int cnt;
int room_size;

bool isValid(int y, int x) {
    return y < m && y >= 0 && x < n && x >= 0 && !visited[y][x];
}

int BFS() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        room_size++;

        for (int i = 0; i < 4; i++) {
            if (((1 << i) & map[y][x]) == 0) {
                int mv_y = y + dy[i];
                int mv_x = x + dx[i];
                if (isValid(mv_y, mv_x)) {
                    q.push({mv_y, mv_x});
                    visited[mv_y][mv_x] = true;
                }
            }
        }
    }
}

void BFS_remove() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        room_size++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (((1 << i) & map[y][x]) == 0) {
                int mv_y = y + dy[i];
                int mv_x = x + dx[i];
                if (isValid(mv_y, mv_x)) {
                    q.push({mv_y, mv_x});
                    visited[mv_y][mv_x] = true;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                cnt++;
                q.push({i, j});
                room_size = 0;
                BFS();
                if( max_room < room_size) max_room = room_size;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            memset(visited, false, sizeof(visited));
            for (int k = 0; k < 4; k++) {
                int tmp = map[i][j];
                cout << ~(1<<k);
                map[i][j] = map[i][j] & ~(1 << k);
                if( map[i][j] == tmp ) continue;
                q.push({i, j});
                room_size = 0;
                BFS_remove();
                remove_max_room = remove_max_room < room_size ? room_size : remove_max_room;
                map[i][j] = tmp;
            }
        }
    }
    cout << cnt << "\n" << max_room << "\n" << remove_max_room;
}