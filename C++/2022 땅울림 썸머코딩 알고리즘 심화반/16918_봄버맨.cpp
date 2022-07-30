#include <iostream>
#include <queue>
using namespace std;

int r, c, n;
pair<char, int> map[202][202];
queue<pair<int,int>> q;
string s;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> r >> c >> n;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            map[i][j] = {s[j], 1};
        }
    }

    if (n == 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << map[i][j].first;//<< "," << map[i][j].second << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    for (int t = 2; t <= n; t++) {
        if (t % 2 == 0) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j].first == '.') {
                        map[i][j] = {'O', 0};
                    } else {
                        map[i][j].second++;
                    }
                }
            }
        } else {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (map[i][j].first == 'O' && map[i][j].second + 1 == 3) {
                        map[i][j] = {'.', 0};
                        for (int k = 0; k < 4; k++) {
                            int ni = i + di[k];
                            int nj = j + dj[k];
                            if (ni < 0 || nj < 0 || ni >= r || nj >= c)continue;
                            q.push({ni,nj});
                        }
                    } else if (map[i][j].first == 'O') {
                        map[i][j].second++;
                    }
                }
            }
            while(!q.empty()){
                int ni = q.front().first;
                int nj = q.front().second;
                q.pop();
                map[ni][nj] = {'.', 0};
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j].first;//<< "," << map[i][j].second << " ";
        }
        cout << "\n";
    }
}