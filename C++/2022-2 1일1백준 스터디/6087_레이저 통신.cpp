#include <queue>
#include <iostream>

#define INF 1000000000

using namespace std;

int w, h;
char map[101][101];
int dp[101][101];
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
pair<int, int> start;
pair<int, int> ended;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};


void BFS() {

    while (!pq.empty()) {
        int cnt = -pq.top().first.first;
        int direct = pq.top().first.second;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if( dp[i][j] < cnt ) continue;
        dp[i][j] = cnt;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
            if (map[ni][nj] == '*') continue;

            int next_cnt = (direct == k) ? cnt : cnt + 1;
            if (dp[ni][nj] < next_cnt) continue;
            dp[ni][nj] = next_cnt;
            pq.push({{-next_cnt, k},
                     {ni,       nj}});
        }
    }
    cout << dp[ended.first][ended.second];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> w >> h;
    string s;
    bool flag = false;
    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j];
            if (s[j] == 'C') {
                if (!flag) {
                    start = {i, j};
                    flag = true;
                } else {
                    ended = {i, j};
                }
            }
        }
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = INF;
        }
    }

    dp[start.first][start.second] = 0;
    for (int k = 0; k < 4; k++) {
        int ni = start.first + di[k];
        int nj = start.second + dj[k];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (map[ni][nj] == '*')continue;
        dp[ni][nj] = 0;
        pq.push({{0,  k},
                 {ni, nj}});
    }

    BFS();
}