#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;

int n, k, ans;
queue<pair<int, int>> q;
bool visited[MAX];

bool check(int i) {
    return i >= 0 && i <= 100000 && !visited[i];
}

void BFS() {
    while (!q.empty()) {
        int cnt = q.front().first;
        int i = q.front().second;
        q.pop();

        if (i == k) {
            ans = cnt;
            return;
        }

        if (check(i * 2)) {
            visited[i * 2] = true;
            q.push({cnt + 1, i * 2});
        }
        if (check(i + 1)) {
            visited[i + 1] = true;
            q.push({cnt + 1, i + 1});
        }
        if (check(i - 1)) {
            visited[i - 1] = true;
            q.push({cnt + 1, i - 1});
        }
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    q.push({0, n});
    visited[n] = true;
    BFS();
    cout << ans;
}