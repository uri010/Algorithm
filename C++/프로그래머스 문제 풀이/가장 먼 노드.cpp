//
// Created by 김유리 on 2023/12/14.
//
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> edges(20001);
bool visited[20001];
int maxDepth = 0;
int dp[20001];

void BFS() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        maxDepth = max(maxDepth, cnt);
        dp[cur] = cnt;

        for (int i = 0; i < edges[cur].size(); i++) {
            if (!visited[edges[cur][i]]) {
                visited[edges[cur][i]] = true;
                q.push({edges[cur][i], cnt + 1});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        int v = edge[i][0];
        int w = edge[i][1];
        edges[v].push_back(w);
        edges[w].push_back(v);
    }
    BFS();
    for (int i = 1; i <= n; i++) {
        if (dp[i] == maxDepth)answer++;
    }
    return answer;
}