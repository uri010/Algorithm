//
// Created by 김유리 on 2023/08/12.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
int map[101][101];
bool visited[101];
int ans[101][101];

void BFS(int i) {
    queue<int> q;
    memset(visited, false, sizeof(visited));
    q.push(i);
    visited[i] = true;


    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int j = 1; j <= N; j++) {
            if (map[now][j] == 1 && j == i && visited[j]) {
                ans[i][j] = 1;
            } else if (map[now][j] == 1 && !visited[j]) {
                visited[j] = true;
                q.push(j);
                ans[i][j] = 1;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        BFS(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}