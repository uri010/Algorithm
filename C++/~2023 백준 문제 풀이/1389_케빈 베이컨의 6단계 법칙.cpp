//
// Created by 김유리 on 2023/08/11.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, A, B;
vector<int> map[101];
bool visited[101];
int kevin[101];
int min_num = 1000;
int min_kevin = 1000000;

void BFS(int a) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));
    q.push({a, 0});
    visited[a] = true;
    kevin[a] = 0;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < map[now].size(); i++) {
            if (!visited[map[now][i]]) {
                visited[map[now][i]] = true;
                q.push({map[now][i], cnt + 1});
                kevin[map[now][i]] = cnt + 1;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        map[A].push_back(B);
        map[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        BFS(i);
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            sum += kevin[j];
        }
        if (sum < min_kevin) {
            min_kevin = sum;
            min_num = i;
        }
    }
    cout << min_num;

}