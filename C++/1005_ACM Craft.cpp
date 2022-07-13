//
// Created by 김유리 on 2022/07/13.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    int n, k, x, y, w;

    while (t--) {
        cin >> n >> k;

        int time[1002] = {0,};
        int in_degree[1002] = {0,};
        for (int i = 1; i <= n; i++) {
            cin >> time[i];
        }

        vector<vector<int>> v;
        v.resize(n+1);
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            in_degree[y]++;
        }
        cin >> w;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 1; i <= n; i++) {
            if (!in_degree[i]) {
                pq.push({time[i], i});
            }
        }

        while (!pq.empty()) {
            int end_time = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            if (num == w) {
                cout << end_time << "\n";
                break;
            }
            for (int next: v[num]) {
                in_degree[next]--;
                if (!in_degree[next]) {
                    pq.push({end_time + time[next], next});
                }
            }
        }
    }
}