//
// Created by 김유리 on 2023/09/05.
//
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
bool visited[101][101];

bool isValid(int i, int j, int i_size, int j_size) {
    return i >= 0 && i < i_size && j >= 0 && j < j_size;
}

int BFS(vector<string> maps, int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int sum = maps[i][j] - '0';

    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (!isValid(ni, nj, maps.size(), maps[0].length()) || visited[ni][nj] || maps[ni][nj] == 'X') continue;
            visited[ni][nj] = true;
            q.push({ni, nj});
            sum += (maps[ni][nj] - '0');
        }
    }
    return sum;
}

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = false;
        }
    }
}

vector<int> solution(vector<string> maps) {
    init();
    vector<int> answer;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(BFS(maps, i, j));
            }
        }
    }

    // 섬이 없으면 -1
    if (answer.empty()) answer.push_back(-1);
    // 오름차순 정렬
    sort(answer.begin(), answer.end());

    return answer;
}