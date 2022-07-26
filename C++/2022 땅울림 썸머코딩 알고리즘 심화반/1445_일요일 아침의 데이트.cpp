//
// Created by 김유리 on 2022/07/24.
//
#include <iostream>
#include <queue>

#define INF 1000000000
using namespace std;

int n, m;
char map[52][52];
pair<int, int> dist[52][52];

pair<int, int> end_point;
pair<int, int> start_point;
vector<pair<int, int>> gar;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1];
            if (map[i][j] == 'F') {
                end_point = {i, j};
            }
            if (map[i][j] == 'S') {
                start_point = {i, j};
            }
            if (map[i][j] == 'g') {
                gar.push_back({i, j});
            }
        }
    }

    for (int k = 0; k < gar.size(); k++) {
        int i = gar[k].first;
        int j = gar[k].second;
        for (int l = 0; l < 4; l++) {
            int ni = i + di[l];
            int nj = j + dj[l];
            if (ni <= 0 || nj <= 0 || ni > n || nj > m) continue;
            if (map[ni][nj] == '.')
                map[ni][nj] = 's';
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j].first = INF;
            dist[i][j].second = INF;
        }
    }

    pq.push({{0,                 0},
             {start_point.first, start_point.second}});

    pair<int, int> result;

    while (!pq.empty()) {
        int garbage = -pq.top().first.first;
        int garbage_side = -pq.top().first.second;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if (i == end_point.first && j == end_point.second) {
            result.first = garbage;
            result.second = garbage_side;
            break;
        }
        if (dist[i][j].first < garbage) continue;
        if (dist[i][j].second < garbage_side) continue;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni <= 0 || nj <= 0 || ni > n || nj > m) continue;

            if (map[ni][nj] == 'g') {
                if (dist[ni][nj].first > garbage + 1) {
                    dist[ni][nj] = {garbage + 1, garbage_side};
                    pq.push({{-(garbage + 1), -garbage_side},
                             {ni,             nj}});
                }
            } else if (map[ni][nj] == 's') {
                if (dist[ni][nj].first <= garbage) continue;
                if (dist[ni][nj].second > garbage_side + 1) {
                    dist[ni][nj] = {garbage, garbage_side + 1};
                    pq.push({{-garbage, -(garbage_side + 1)},
                             {ni,       nj}});
                }
            } else {
                if (dist[ni][nj].first <= garbage) continue;
                dist[ni][nj] = {garbage, garbage_side};
                pq.push({{-garbage, -garbage_side},
                         {ni,       nj}});
            }
        }
    }

    cout << result.first << " " << result.second;

}