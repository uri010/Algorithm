//
// Created by 김유리 on 2022/07/23.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<vector<pair<int, int>>> v;
bool visited[10002];
int max_length;
int max_vertex;

void dfs(int x, int length) {

    if (max_length < length) {
        max_length = length;
        max_vertex = x;
    }
    for (auto y: v[x]) {
        int next = y.first;
        int cost = y.second;
        if (!visited[next]) {
            visited[next] = true;
            dfs(next, length + cost);
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n + 2);
    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    visited[1] = true;
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    visited[max_vertex] = true;
    dfs(max_vertex, 0);
    cout << max_length;

}