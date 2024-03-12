//
// Created by 김유리 on 2024/03/12.
//
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
string map[51];
bool visited[51][51];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int maxDist = 0;

bool isValid(int i, int j) {
    return i >= 0 && i < H && j >= 0 && j < W;
}

void BFS(int i, int j) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {i, j}});
    visited[i][j] = true;

    while (!q.empty()) {
        int cnt = q.front().first;
        i = q.front().second.first;
        j = q.front().second.second;
        q.pop();

        maxDist = max(cnt, maxDist);

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!isValid(ni, nj) || visited[ni][nj] || map[ni][nj] != 'L') continue;
            q.push({cnt + 1, {ni, nj}});
            visited[ni][nj] = true;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    string input;
    vector<pair<int, int>> v;
    for (int i = 0; i < H; i++) {
        cin >> input;
        map[i] = input;
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == 'L') v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++) {
        BFS(v[i].first, v[i].second);
    }
    cout << maxDist;
}