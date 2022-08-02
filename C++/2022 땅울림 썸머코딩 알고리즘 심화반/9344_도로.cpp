//
// Created by 김유리 on 2022/08/02.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int t, n, m, p, q;
int u, v, w;
int par[10002];
vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void init() {
    edge.clear();
    edge.resize(n + 1);
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        pq.push({-w, {u, v}});
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m >> p >> q;
        init();
        int cnt = 1;
        int flag = 0;
        while (!pq.empty()) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            int ni = Find(i);
            int nj = Find(j);
            if (ni != nj) {
                par[nj] = ni;
                if (i == p && j == q) flag = 1;
                cnt++;
                if (cnt == n) break;
            }
        }

        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}