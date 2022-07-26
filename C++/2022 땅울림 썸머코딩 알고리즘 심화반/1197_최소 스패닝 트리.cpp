//
// Created by 김유리 on 2022/07/27.
//
#include <iostream>
#include <queue>

using namespace std;

int v, e;
int a, b, c;
priority_queue<pair<int, pair<int, int>>> pq;
int par[10002];
long long sum;

int Find(int x) {
    if (x == par[x])
        return x;

    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    for (int i = 1; i <= v; i++) {
        par[i] = i;
    }

    int cnt = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        pq.pop();

        v1 = Find(v1);
        v2 = Find(v2);
        if (v1 != v2) {
            par[v2] = v1;
            cnt++;
            sum += cost;
            if (cnt == v - 1) break;
        }
    }
    cout << sum;


}