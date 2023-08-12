//
// Created by 김유리 on 2023/08/12.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;
int cnt;
int map[101][101];
bool visited[101][101];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

bool isValid(int i, int j) {
    return i > 0 && i <= M && j > 0 && j <= N;
}

int BFS(int i, int j) {
    queue<pair<int, int>> q;
    int area = 0;
    q.push({i, j});
    visited[i][j] = true;
    area++;

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int to_i = i + di[k];
            int to_j = j + dj[k];

            if (!isValid(to_i, to_j)) continue;
            if (visited[to_i][to_j]) continue;

            visited[to_i][to_j] = true;
            area++;
            q.push({to_i, to_j});
        }
    }
    return area;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> M >> N >> K;
    int x1, y1, x2, y2;
    vector<int> v;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1 + 1; j <= x2; j++) {
            for (int i = y1 + 1; i <= y2; i++) {
                visited[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                cnt++;
                v.push_back(BFS(i, j));
            }
        }
    }
    cout << cnt << "\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


}