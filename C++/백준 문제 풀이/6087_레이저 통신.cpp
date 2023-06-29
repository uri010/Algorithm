#include <iostream>
#include <queue>

#define INF 1000000000
using namespace std;

int w, h;
char map[101][101];
int cnt[101][101];
queue <pair<int, int>> q;
pair<int, int> start = {-1, -1};
pair<int, int> fin = {-1, -1};

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};


void Input() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j];
            if (map[i][j] == 'C') {
                if (start.first == -1) start = {i, j};
                else fin = {i, j};
            }
            cnt[i][j] = 0;
        }
    }
}

void BFS() {
    q.push({start.first, start.second});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            while (true) {
                if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
                if (map[ni][nj] == '*') break;
                if (cnt[ni][nj] == 0) {
                    cnt[ni][nj] = cnt[i][j] + 1;
                    q.push({ni, nj});
                }
                ni += di[k];
                nj += dj[k];
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    Input();
    BFS();
    cout << cnt[fin.first][fin.second] - 1;
}