//
// Created by 김유리 on 2022/07/26.
//
#include <iostream>

using namespace std;
#define INF 2100000000

int n, m;
int dist[102][102];
int a, b, c;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (dist[j][i] == INF || dist[i][k] == INF) continue;
                if (dist[j][i] + dist[i][k] < dist[j][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF || i==j)
                cout << "0 ";
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}