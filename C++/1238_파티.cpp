#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 2100000000
using namespace std;

int n, m, x;
int a, b, c;
vector<vector<pair<int, int>>> v;
int dist[1002];
int dist2[1002][2];

priority_queue<pair<int, int>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x;
    v.resize(n + 2);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        dist2[i][1] = INF;
    }
    dist2[x][1] = 0;

    for (int i = 1; i <= n; i++) {
        pq.push({0, i});
        for(int j=1;j <=n;j++){
            if( i==j ) dist[j] = 0;
            dist[j] = INF;
        }
        while (!pq.empty()) {
            int cost = -pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if (dist[now] < cost) continue;

            for (auto u: v[now]) {
                int next = u.first;
                int next_cost = u.second + cost;

                if (dist[next] <= next_cost) continue;
                dist[next] = next_cost;
                pq.push({-(next_cost), next});
            }
        }
        dist2[i][0] = dist[x];
    }



    pq.push({0, x});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist2[now][1] < cost) continue;

        for (auto u: v[now]) {
            int next = u.first;
            int next_cost = u.second + cost;

            if (dist2[next][1] <= next_cost) continue;
            dist2[next][1] = next_cost;
            pq.push({-(next_cost), next});
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = dist2[i][0] + dist2[i][1];
        result = max(result, tmp);
    }
    cout << result;

}