//
// Created by 김유리 on 2022/07/20.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int map[501][501];
int tmp[501][501];
int n;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int dfs(int i, int j) {
    if (tmp[i][j] != -1) {
        return tmp[i][j];
    }
    int max_cnt = 0;
    for (int k = 0; k < 4; k++) {
        int to_i = i + di[k];
        int to_j = j + dj[k];
        if (to_i < 0 || to_j < 0 || to_i >= n || to_j >= n) continue;
        if (map[to_i][to_j] > map[i][j]) {
            max_cnt = max(max_cnt, dfs(to_i, to_j));
        }
    }
    tmp[i][j] = max_cnt + 1;
    return tmp[i][j];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int result = 0;
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(i, j));
        }
    }
    cout << result;

}