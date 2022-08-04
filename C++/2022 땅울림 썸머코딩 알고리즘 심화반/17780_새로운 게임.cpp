//
// Created by 김유리 on 2022/08/02.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int a, b, c;
int map[13][13];
vector<pair<int, int>> piece[13][13];
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

int di[] = {0, 0, 0, -1, 1};
int dj[] = {0, 1, -1, 0, 0};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        piece[a][b].push_back({i, c});
        pq.push({{-i, c},
                 {a,  b}});
    }

    int cnt = 0;
    while (cnt <= 1000) {
        cnt++;

        while (!pq.empty()) {
            int num = -pq.top().first.first;
            int direct = pq.top().first.second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (piece[i][j][0].first != num) continue;
            int ni = i + di[direct];
            int nj = j + dj[direct];
            if (ni <= 0 || nj <= 0 || ni > n || nj > n || map[ni][nj] == 2) {
                if (direct == 1 || direct == 3) {
                    direct += 1;
                } else if (direct == 2 || direct == 4) {
                    direct -= 1;
                }
                ni = i + di[direct];
                nj = j + dj[direct];
                piece[i][j][0].second = direct;
                if (ni <= 0 || nj <= 0 || ni > n || nj > n || map[ni][nj] == 2) {
                    continue;
                }
            }
            if (map[ni][nj] == 1) {
                reverse(piece[i][j].begin(), piece[i][j].end());
            }
            for (auto x: piece[i][j]) {
                piece[ni][nj].push_back({x.first, x.second});
            }
            if (piece[ni][nj][0].first > num) {
                pq.push({{-piece[ni][nj][0].first, piece[ni][nj][0].second},
                         {ni,                      nj}});
            }
            piece[i][j].resize(0);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (piece[i][j].size() >= 4) {
                    cout << cnt;
                    return 0;
                }
                if (piece[i][j].size() != 0) {
                    pq.push({{-piece[i][j][0].first,
                                     piece[i][j][0].second},
                             {i,     j}});
                }
            }
        }
    }
    cout << -1;
}