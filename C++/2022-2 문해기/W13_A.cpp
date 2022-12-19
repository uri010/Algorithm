//
// Created by 김유리 on 2022/11/25.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int map[1002];
vector<vector<pair<int, int>>> v;
bool visited[1002];
int t, n, m, a, b;

int cnt;

void DFS(int now) {
    cnt++;
    cout << now << "\n";

    for (auto x: v[now]) {
        int next = x.second;
        if (visited[next]) continue;
        visited[next] = true;
        DFS(next);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cnt = 0;
        v.clear();
        v.resize(1002);
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        int min_height = 1000000;
        int min_vertex = 0;
        for (int i = 0; i < n; i++) {
            cin >> map[i];
            if (min_height > map[i]) {
                min_vertex = i;
                min_height = map[i];
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back({map[b], b});
            v[b].push_back({map[a], a});
        }

        for (int i = 0; i < n; i++) {
            sort(v[i].begin(), v[i].end());
        }

        visited[min_vertex] = true;

        DFS(min_vertex);

        while (cnt < n) {
            min_height = 1000000;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && min_height > map[i]) {
                    min_height = map[i];
                    min_vertex = i;
                }
            }
            visited[min_vertex] = true;

            DFS(min_vertex);
        }

    }
}