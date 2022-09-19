//
// Created by 김유리 on 2022/09/19.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, x, y;
int tree[100001];
vector<vector<int>> v;
queue<int> q;

void BFS() {
    while (!q.empty()) {
        int i = q.front();
        q.pop();

        for (int k: v[i]) {
            if (tree[k] == 0) {
                tree[k] = i;
                q.push(k);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    tree[1] = 1;
    for (int k: v[1]) {
        tree[k] = 1;
        q.push(k);
    }

    BFS();

    for (int i = 2; i <= n; i++) {
        cout << tree[i] << "\n";
    }


}