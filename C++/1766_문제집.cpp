//
// Created by 김유리 on 2022/07/21.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int in_degree[33000];
vector<vector<int>> v;
priority_queue<int> q;

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

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(-i);
        }
    }

    while (!q.empty()) {
        int num = -q.top();
        q.pop();
        cout << num << " ";

        for (int next: v[num]) {
            if (--in_degree[next] == 0) {
                q.push(-next);
            }
        }
    }
}