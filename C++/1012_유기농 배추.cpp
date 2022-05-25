//
// Created by 김유리 on 2022/05/25.
//
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int map[51][51];
bool visited[51][51];
queue <pair<int,int>> q;
int m, n, k;

int mv_x[4] = {1,-1,0,0};
int mv_y[4] = {0,0,1,-1};

void BFS() {
    while(!q.empty()){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i <4; i++) {
            int to_x = x + mv_x[i];
            int to_y = y + mv_y[i];
            if (to_x >= 0 && to_x < n && to_y >= 0 && to_y < m) {
                if (!visited[to_x][to_y] && map[to_x][to_y] == 1) {
                    visited[to_x][to_y] = true;
                    q.push({to_x, to_y});
                }
            }
        }
    }
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while( t--) {
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }


        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && map[i][j] == 1) {
                    q.push({i, j});
                    BFS();
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }
}