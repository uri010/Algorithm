#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

char map[101][101];
char map2[101][101];
bool visited[101][101];
int n, cnt, cnt2;

int mv_x[4] = {1,-1,0,0};
int mv_y[4] = {0,0,1,-1};
queue<pair<int, int>> q;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >=0 && y < n && !visited[x][y];
}

void BFS_n(char color){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int to_x = x + mv_x[i];
            int to_y= y + mv_y[i];
            if(isValid(to_x, to_y) ) {
                if (map[to_x][to_y] == color) {
                    visited[to_x][to_y] = true;
                    q.push({to_x, to_y});
                }
            }
        }
    }
}
void BFS_s(char color){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int to_x = x + mv_x[i];
            int to_y= y + mv_y[i];
            if(isValid(to_x, to_y) && map2[to_x][to_y] == color){
                visited[to_x][to_y] = true;
                q.push({to_x, to_y});
            }
        }
    }
}

int main (){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin >> n;
    string s;
    for(int i=0; i < n ;i++){
        cin >> s;
        for(int j=0; j < s.size(); j++){
            map[i][j] = s[j];
            if( s[j] == 'G') {
                map2[i][j] = 'R';
            }
            else{
                map2[i][j] = s[j];
            }
        }
    }
    for(int i=0;  i < n; i++){
        for(int j=0;j < n; j ++){
            if( !visited[i][j]) {
                q.push({i, j});
                BFS_n(map[i][j]);
                cnt++;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    for(int i=0;  i < n; i++){
        for(int j=0;j < n; j ++){
            if( !visited[i][j]) {
                q.push({i, j});
                BFS_s(map2[i][j]);
                cnt2++;
            }
        }
    }
    cout << cnt << " " << cnt2;
}