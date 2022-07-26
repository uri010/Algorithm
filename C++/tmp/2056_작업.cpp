//
// Created by 김유리 on 2022/07/16.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> v;
int in_degree[10003];
int cost[10003];
queue<pair<int, int>>
        tmp;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n + 2);

    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i] >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v[b].push_back(i);
            in_degree[i]++;
        }
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push({-cost[i], i});
        }
    }
    int time = 0;
    while (!pq.empty()) {
        int end_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        if (time < end_time) time = end_time;
        for (int next: v[num]) {
            in_degree[next]--;
            if (!in_degree[next]) {
                pq.push({-(end_time + cost[next]), next});
            }
        }
    }
    cout << time;
    /*2번째 방법
    int time = 0;
    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now = pq.top().second;
        int size = pq.size();
        pq.pop();
        time += now_cost;

        for (int i = 0; i < size - 1; i++) {
            int same_time_cost = -pq.top().first - now_cost;
            int same_time_vertex = pq.top().second;
            pq.pop();
            tmp.push({same_time_cost, same_time_vertex});
        }
        while (!tmp.empty()) {
            pq.push({-tmp.front().first, tmp.front().second});
            tmp.pop();
        }


        for (int next: v[now]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                pq.push({-cost[next], next});
            }
        }
    }
    cout << time;
*/
}