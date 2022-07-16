#include <iostream>
#include <vector>

using namespace std;
#define INF 2100000000

int n, m, a, b, c;
vector<vector<pair<int, int>>> v;
bool visited[100003];
int result;

void dfs(int now, int cost, int min_cost) {
    if (now == b) {
        if (min_cost > result) {
            result = min_cost;
        }
        return;
    }

    for (auto v: v[now]) {
        int next = v.first;
        int next_cost = v.second;
        if (!visited[next]) {
            visited[next] = true;
            if (min_cost > next_cost) {
                dfs(next, next_cost, next_cost);
            } else {
                dfs(next, next_cost, min_cost);
            }
            visited[next] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n + 2);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> a >> b;
    visited[a] = true;
    dfs(a, 0, INF);
    cout << result;
}