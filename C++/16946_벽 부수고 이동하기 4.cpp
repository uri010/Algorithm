#include <iostream>
#include <queue>

using namespace std;

int n, m, num = 1;
int map[1002][1002];
bool visited[1002][1002];
pair<int, int> dist[1002][1002];

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(vector<pair<int, int>> v) {
    int cnt = 0;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        cnt++;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni <= 0 || nj <= 0 || ni > n || nj > m)continue;
            if (!visited[ni][nj] && map[ni][nj] == 0) {
                visited[ni][nj] = true;
                v.push_back({ni, nj});
                q.push({ni, nj});
            }
        }
    }
    for (int k = 0; k < v.size(); k++) {
        int i = v[k].first;
        int j = v[k].second;
        dist[i][j] = {cnt, num};
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j + 1] = s[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vector<pair<int, int>> v;
            if (map[i][j] == 0 && !visited[i][j]) {
                v.push_back({i, j});
                q.push({i, j});
                visited[i][j] = true;
                num++;
                bfs(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cnt = 0;
            if (map[i][j] == 1) {
                cnt++;
                vector<int> tmp;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni <= 0 || nj <= 0 || ni > n || nj > m)continue;
                    if (map[ni][nj] == 0 && dist[ni][nj].first != 0) {
                        int flag = 0;
                        for (int l = 0; l < tmp.size(); l++) {
                            if (tmp[l] == dist[ni][nj].second) {
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            tmp.push_back(dist[ni][nj].second);
                            cnt += dist[ni][nj].first;
                        }
                    }
                }
            }
            cout << cnt % 10;
        }
        cout << "\n";
    }
}