#include <iostream>
#include <queue>
using namespace std;

char map[51][51];
bool visited[51][51];
int n , m, cnt;

queue<pair<int,int>> q;

void BFS_N(){
    while(!q.empty()){
        int x = q.front().first;
        int y  = q.front().second;
        q.pop();

        if( x+1 < n && map[x+1][y] == '|' && !visited[x+1][y]) {
            q.push({x+1, y});
            visited[x+1][y] = true;
        }
    }
    cnt++;

}
void BFS_M(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if( y+1 < m && map[x][y+1] == '-' && !visited[x][y+1]){
            q.push({x, y+1});
            visited[x][y+1] = true;
        }
    }
    cnt++;
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j ++){
            if( !visited[i][j] ){
                q.push({i,j});
                if( map[i][j] == '|')
                    BFS_N();
                else
                    BFS_M();
            }
        }
    }
    cout << cnt ;
}