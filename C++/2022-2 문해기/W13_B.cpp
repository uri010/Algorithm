//
// Created by 김유리 on 2022/11/25.
//
#include <iostream>

using namespace std;

int dist[252][252];
int t, n, m, u, v, w, q;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m >> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = INT32_MAX;
                if (i == j) dist[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[k][i] == INT32_MAX || dist[i][j] == INT32_MAX) continue;
                    dist[k][j] = min(dist[k][j], dist[k][i] + dist[i][j]);
                }
            }
        }
        for (int i = 0; i < q; i++) {
            cin >> u >> v;
            cout << dist[u][v] << "\n";
        }
    }

}