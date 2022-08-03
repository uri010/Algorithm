//
// Created by 김유리 on 2022/08/02.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int a, b, c;
int map[13][13];
int par[13];
vector<pair<int, int>> piece[13][13];
queue<pair<int, pair<int, int>>> q;

int dj[4] = {1, -1, 0, 0};
int di[4] = {0, 0, -1, 1};

int Find(int x) {
    if (par[x] == x) return x;
    return par[x] = Find(par[x]);
}

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

    for (int i = 1; i <= k; k++) {
        cin >> a >> b >> c;
        piece[a][b].push_back({c, 1});
        q.push({i, {a, b}});
    }

    int cnt = 0;
    int flag = 0;
    while (cnt <= 1000) {
        for (int l = 1; l <= k; l++) {
            int now = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            int direct = piece[i][j][0].first;
            int ni = i + di[direct];
            int nj = j + di[direct];
            if (ni <= 0 || nj <= 0 || ni > n || nj > n || map[ni][nj] == 3) {
                if (direct == 1) {
                    direct = 2;
                    nj = j + dj[direct];
                } else if (direct == 2) {
                    direct = 1;
                    nj = j + dj[direct];
                } else if (direct == 3) {
                    direct = 4;
                    ni = i + di[direct];
                } else if (direct == 4) {
                    direct = 3;
                    ni = i+ di[direct];
                }
                if( ni <=0 || nj <=0 || ni > n || nj > n || map[ni][nj] == 3) {
                    q.push({piece[ni][nj][0].first,
                }

            }

            if (map[ni][nj] == 0) {

            }
            if (map[ni][nj] == 1) {

            }

        }
    }


}