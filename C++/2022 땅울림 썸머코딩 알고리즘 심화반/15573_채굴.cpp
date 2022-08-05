//
// Created by 김유리 on 2022/08/05.
//
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[1005][1005];
bool visited[1005][1005];

int n, m, k;
int cnt;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int solve(int mid) {
    memset(visited, false, sizeof(visited));
    while (!q.empty()) q.pop();

    cnt = 0;
    if (m == 1) {
        for (int i = 1; i <= n; i++)
            if (map[i][1] <= mid)
                cnt++;
        return cnt;
    }
    if( n==1) {
        for(int i=1;i <=m; i++){
            if( map[1][i] <=mid)
                cnt++;
            return cnt;
        }
    }

    for(int i=1;i <=m; i++){
        if( map[1][i] <= mid) {
            visited[1][i] = true;
            q.push({1, i});
        }
    }
    for(int i=2; i<=n; i++){
        if( map[i][1] <= mid) {
            visited[i][1] = true;
            q.push({i, 1});
        }
        if( map[i][m] <= mid) {
            visited[i][m] = true;
            q.push({i, m});
        }
    }
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        cnt++;

        for (int a = 0; a < 4; a++) {
            int ni = i + di[a];
            int nj = j + dj[a];
            if (ni <= 0 || nj <= 0 || ni > n || nj > m) continue;
            if (map[ni][nj] <= mid && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    int left = 1;
    int right = 1000000;
    int ans = 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (solve(mid) >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
}