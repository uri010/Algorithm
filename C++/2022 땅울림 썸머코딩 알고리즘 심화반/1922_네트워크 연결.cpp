//
// Created by 김유리 on 2022/08/01.
//
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a, b, c;
int par[1002];
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int cnt = 0;
    int sum = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        i = Find(i);
        j = Find(j);
        if (i != j) {
            par[j] = i;
            cnt++;
            sum += cost;
            if (cnt == n - 1) break;
        }
    }
    cout << sum;

}
