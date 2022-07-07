#include <iostream>
#include <queue>
using namespace std;

char map[251][251];
bool visited[251][251];
int wolves, sheep;
int r, c;
queue<pair<int, int>> q;

int mv_x[4] = {1, -1, 0 , 0};
int mv_y[4] = {0,0, 1, -1};

bool isValid(int x, int y) {
    return x >=0 && x < r && y >=0 && y <c && !visited[x][y] && map[x][y] != '#';
}

void BFS(){
    int w = 0, s =0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(map[x][y] == 'v') w++;
        else if( map[x][y] == 'k') s++;

        for(int i=0; i < 4; i++){
            int to_x = x + mv_x[i];
            int to_y = y + mv_y[i];

            if(isValid(to_x, to_y)){
                visited[to_x][to_y] = true;
                q.push({to_x, to_y});
            }
        }
    }
    if( w >= s) wolves += w;
    else sheep += s;
}


int main (){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> r >> c;

    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            if( map[i][j] != '#' && !visited[i][j]){
                q.push({i, j});
                visited[i][j] = true;
                BFS();
            }
        }
    }
    cout <<sheep << " " << wolves;

}