//
// Created by 김유리 on 2023/08/14.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans;
int map[9][9];
int tmp[9][9];
bool visited[9][9];
vector<pair<int, int>> v;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    visited[i][j] = true;

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!isValid(ni, nj) || tmp[ni][nj] == 1) continue;
            if (!visited[ni][nj]) {
                tmp[ni][nj] = 2;
                visited[ni][nj] = true;
                q.emplace(ni, nj);
            }
        }
    }
}

void Copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = map[i][j];
        }
    }
}

void Comb(vector<pair<int, int>> comb, int r, int index, int depth) {
    if (r == 0) {
        Copy();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 3; i++) {
            tmp[comb[i].first][comb[i].second] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tmp[i][j] == 2 && !visited[i][j]) {
                    BFS(i, j);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tmp[i][j] == 0) cnt++;
            }
        }
        if (ans < cnt) ans = cnt;
    } else if (depth == v.size()) {
        return;
    } else {
        comb[index] = v[depth];
        Comb(comb, r - 1, index + 1, depth + 1);

        Comb(comb, r, index, depth + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                v.emplace_back(i, j);
        }
    }

    vector<pair<int, int>> comb(3);
    Comb(comb, 3, 0, 0);
    cout << ans;
}