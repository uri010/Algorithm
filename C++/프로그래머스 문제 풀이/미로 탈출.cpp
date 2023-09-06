//
// Created by 김유리 on 2023/09/06.
//
#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> lever;
bool visited[101][101];

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = false;
        }
    }
}

int BFS(vector<string> maps, pair<int, int> s, char m) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, s});
    visited[s.first][s.second] = true;

    while (!q.empty()) {
        int cnt = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || nj < 0 || ni >= maps.size() || nj >= maps[0].size()) continue;
            if (visited[ni][nj] || maps[ni][nj] == 'X') continue;
            if (maps[ni][nj] == m) return cnt + 1;
            visited[ni][nj] = true;
            q.push({cnt + 1, {ni, nj}});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] == 'S') {
                answer += BFS(maps, {i, j}, 'L');
                if (answer == -1) {
                    return -1;
                }
            } else if (maps[i][j] == 'L') {
                lever = {i, j};
            }
        }
    }
    init();
    int tmp = BFS(maps, lever, 'E');
    if (tmp == -1) return -1;
    answer += tmp;
    return answer;
}