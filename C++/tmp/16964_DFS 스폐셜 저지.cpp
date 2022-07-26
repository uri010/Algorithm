//
// Created by 김유리 on 2022/07/27.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
int a, b;
vector<vector<int>> edge;
vector<int> input;
bool visited[100002];
int cnt;

void dfs(int x) {
    visited[x] = true;
    cnt++;

    while (true) {
        int flag = 0;
        for (int next: edge[x]) {
            if (next == input[cnt] && !visited[next]) {
                dfs(next);
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        else break;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    edge.resize(n + 2);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> a;
        input.push_back(a);
    }

    dfs(1);

    if (cnt < n) cout << 0;
    else cout << 1;
}