//
// Created by 김유리 on 2022/08/23.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, r;
int map[302][302];
bool visited[302][302];
vector<queue<int>> q;
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};


void set(int i, int j) {
    int ni = i;
    int nj = j;
    int dir = 0; //아래 오른쪽 위 왼쪽
    queue<int> tmp;
    while (!visited[ni][nj]) {
        visited[ni][nj] = true;
        tmp.push(map[ni][nj]);
        ni = ni + di[dir];
        nj = nj + dj[dir];
        if (visited[ni][nj] || ni <= 0 || nj <= 0 || ni > n || nj > m) {
            ni = ni - di[dir];
            nj = nj - dj[dir];
            dir++;
            if (dir == 4) break;
            ni = ni + di[dir];
            nj = nj + dj[dir];
        }
    }
    q.push_back(tmp);
}

void solve(int i, int j) {
    int ni = i;
    int nj = j;
    int dir = 0; //아래 오른쪽 위 왼쪽
    while (!visited[ni][nj]) {
        visited[ni][nj] = true;
        map[ni][nj] = q[i-1].front();
        q[i-1].pop();
        ni = ni + di[dir];
        nj = nj + dj[dir];
        if (visited[ni][nj] || ni <= 0 || nj <= 0 || ni > n || nj > m) {
            ni = ni - di[dir];
            nj = nj - dj[dir];
            dir++;
            if (dir == 4) break;
            ni = ni + di[dir];
            nj = nj + dj[dir];
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                set(i, j);
                i++;
            }
        }
    }


    for (int i = 0; i < q.size(); i++) {
        if (!q[i].empty()) {
            int length = q[i].size();
            int turn = length - r % length;
            while (turn--) {
                int x = q[i].front();
                q[i].pop();
                q[i].push(x);
            }
        }
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j]) {
                solve(i, j);
                i++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

}

