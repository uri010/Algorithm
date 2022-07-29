//
// Created by 김유리 on 2022/07/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a, b;
vector<vector<int>> edge;
vector<int> input;
bool visited[100002];
int order[100002];
vector<int> result;

void dfs(int x) {
    visited[x] = true;
    result.push_back(x);

    for (int next: edge[x]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

bool compare(int &a, int &b) {
    return order[a] < order[b];
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

    for (int i = 0; i <n; i++) {
        cin >> a;
        input.push_back(a);
        order[a] = i;
    }

    for (int i = 1; i <= n; i++) {
        sort(edge[i].begin(), edge[i].end(), compare);
    }

    dfs(1);
    if (result == input) cout << 1;
    else cout << 0;

}