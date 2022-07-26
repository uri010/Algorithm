#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<pair<int, int>>> v;
bool visited[10002];
int n, m, a, b, c;

bool dfs(int now, int limit) {
    visited[now] = true;

    if (now == b) return true;

    for (auto x: v[now]) {
        int next = x.first;
        int cost = x.second;
        if (!visited[next] && limit <= cost) {
            if (!dfs(next, limit))continue;
            else return true;
        }
    }
    return false;
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

    int left = 0;
    int right = 1000000000;
    int mid, ans;
    while (left <= right) {
        memset(visited, false, sizeof(visited));
        mid = (left + right) / 2;
        if (dfs(a, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans;
}