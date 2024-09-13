//
// Created by 김유리 on 2024/01/13.
//
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int edge;
int arr[201];
int plan, groupNum;
bool visited[201];
vector<vector<int>> edges(201);

void DFS(int cur, int num) {
    visited[cur] = true;
    arr[cur] = num;
    for (int i = 0; i < edges[cur].size(); i++) {
        if (!visited[edges[cur][i]]) {
            DFS(edges[cur][i], num);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> edge;
            if (edge)
                edges[i + 1].push_back(j + 1);
        }
    }

    int num = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i, num);
            num++;
        }
    }

    cin >> plan;
    groupNum = arr[plan];
    for (int i = 1; i < M; i++) {
        cin >> plan;
        if (arr[plan] != groupNum) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}