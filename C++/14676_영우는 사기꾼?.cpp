//
// Created by 김유리 on 2022/07/22.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int build[100002];
vector<vector<int>> v;
vector<pair<int, int>> input;
int in_degree[100002];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    v.resize(n + 2);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        input.push_back({a, b});
    }

    for (int i = 0; i < k; i++) {
        int code = input[i].first;
        int now = input[i].second;

        if (code == 1) {
            if (build[now] != 0 && in_degree[now] == 0) {
                build[now]++;
            } else if (in_degree[now] == 0) {
                build[now]++;
                for (int next: v[now]) {
                    if (in_degree[next] == 0) continue;
                    in_degree[next]--;
                }
            } else {
                cout << "Lier!";
                return 0;
            }
        } else {
            if (build[now] != 0) {
                build[now]--;
                if (build[now] == 0) {
                    for (int next: v[now]) {
                        in_degree[next]++;
                    }
                }
            } else {
                cout << "Lier!";
                return 0;
            }
        }
    }
    cout << "King-God-Emperor";

}