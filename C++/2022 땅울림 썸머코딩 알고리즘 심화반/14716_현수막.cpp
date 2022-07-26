//
// Created by 김유리 on 2022/07/16.
//
#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[251][251];
bool visited[251][251];
queue<pair<int,int>> q;

int dx[8] = { 1, -1, 0 , 0 , 1, -1, 1, -1};
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1};

bool isValid(int y, int x){
    return x >=0 && y >=0 && x < n && y < m && !visited[y][x];
}

void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i < 8; i++){
            int mv_y = y + dy[i];
            int mv_x = x + dx[i];
            if( isValid(mv_y, mv_x) && map[mv_y][mv_x] == 1) {
                q.push({mv_y, mv_x});
                visited[mv_y][mv_x]= true;
            }
        }
    }
}

int main (){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for(int i=0; i < m; i++){
        for(int j=0;j < n; j++){
            cin>> map[i][j];
        }
    }
    int cnt =0;
    for(int i=0; i < m; i++){
        for(int j=0;j < n; j++){
            if(map[i][j] == 1 && !visited[i][j] ) {
                visited[i][j] = true;
                q.push({i, j});
                BFS();
                cnt++;
            }
        }
    }
    cout << cnt;
}