//
// Created by 김유리 on 2022/07/25.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 2000000000
using namespace std;

int N, Q;
int p, q, r;
int k, v;
int usado[5002][5002];
bool visited[5002];
vector<vector<pair<int, int>>> edge;
queue<pair<int, int>> qu;

void BFS(int x) {
    memset(visited, false, sizeof(visited));
    qu.push({x, INF});
    visited[x] = true;
    usado[x][x] = INF;
    while (!qu.empty()) {
        int now = qu.front().first;
        int usa = qu.front().second;
        qu.pop();

        for (auto u: edge[now]) {
            int next = u.first;
            int next_usa = min(u.second, usa);
            if (!visited[next]) {
                visited[next] = true;
                usado[x][next] = next_usa;
                qu.push({next, next_usa});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> Q;
    edge.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;
        edge[p].push_back({q, r});
        edge[q].push_back({p, r});
    }

    for (int i = 1; i <= N; i++) {
        BFS(i);
    }

    while (Q--) {
        int result = 0;
        cin >> k >> v;
        for (int i = 1; i <= N; i++) {
            if (i == v) continue;
            if (k <= usado[v][i]) result++;
        }
        cout << result << "\n";
    }


}
