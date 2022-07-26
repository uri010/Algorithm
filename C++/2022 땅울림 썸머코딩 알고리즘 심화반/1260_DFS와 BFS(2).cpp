//
// Created by 김유리 on 2022/07/19.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> edge;
bool visited[1001];
queue<int> q;

void BFS() {
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int x: edge[now]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void DFS(int now) {
    visited[now] = true;
    cout << now << " ";

    for (int x: edge[now]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> v;
    edge.resize(n + 2);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    DFS(v);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    BFS();

}