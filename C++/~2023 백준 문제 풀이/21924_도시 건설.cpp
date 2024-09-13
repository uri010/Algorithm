//
// Created by 김유리 on 2023/08/26.
//
#include <iostream>
#include <queue>

using namespace std;

int N, M, a, b, c;
long long total;
long long ans;
int cnt;
int par[100001];
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
        total += c;
    }

    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int v = pq.top().second.first;
        int w = pq.top().second.second;
        pq.pop();

        v = Find(v);
        w = Find(w);
        if (v != w) {
            par[w] = v;
            cnt++;
            ans += cost;
        }
    }
    if (cnt != N - 1) cout << -1 << "\n";
    else cout << total - ans << "\n";
}