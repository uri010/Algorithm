//
// Created by 김유리 on 2024/01/28.
//
#include <string>
#include <vector>
#include <cstring>

using namespace std;

pair<int, int> cnt[101];
bool visited[101];
vector<vector<int>> edges(101);

void DFS(int cur, int r) {
    visited[cur] = true;
    if (cur != r) {
        cnt[r].second++;
        cnt[cur].first++;
    }
    for (int i = 0; i < edges[cur].size(); i++) {
        if (!visited[edges[cur][i]]) {
            DFS(edges[cur][i], r);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 0; i < results.size(); i++) {
        int winner = results[i][0];
        int loser = results[i][1];
        edges[winner].push_back(loser);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        DFS(i, i);
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i].first + cnt[i].second == n - 1) answer++;
    }
    return answer;
}