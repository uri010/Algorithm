//
// Created by 김유리 on 2023/08/10.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, A, B;
vector<int> v[10001];
bool visited[10001];

int BFS(int s) {
    queue<int> q;
    memset(visited, false, sizeof(visited));

    int cnt = 1;
    q.push(s);
    visited[s] = true;


    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            if (!visited[v[cur][i]]) {
                visited[v[cur][i]] = true;
                cnt++;
                q.push(v[cur][i]);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[B].push_back(A);
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= N; i++) {
        pq.push({BFS(i), -i});
    }

    int max_cnt = pq.top().first;
    while (pq.size() != 0 && pq.top().first == max_cnt) {
        cout << -pq.top().second << " ";
        pq.pop();
    }
    return 0;
}