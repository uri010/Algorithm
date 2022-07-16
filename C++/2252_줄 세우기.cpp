//
// Created by 김유리 on 2022/07/16.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> v;
int in_degree[32002];
bool visited[32002];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n + 2);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int x: v[now]) {
            in_degree[x]--;
            if (in_degree[x] == 0 && !visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}