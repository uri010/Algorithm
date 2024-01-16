//
// Created by 김유리 on 2024/01/16.
//
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> edges(200);
int visited[200];

void DFS(int cur) {
    visited[cur] = true;
    for (int i = 0; i < edges[cur].size(); i++) {
        if (!visited[edges[cur][i]]) {
            DFS(edges[cur][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (i == j) continue;
            if (computers[i][j] == 1) {
                edges[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
            answer++;
        }
    }
    return answer;
}