#include <iostream>
#include <queue>
using namespace std;

int map[201][201];
bool visited[201][201];
int n, r1,c1,r2,c2;
queue<pair<int,pair<int,int>>> q; // {cnt, r, c}

int mv_r[6] = { -2, -2, 0, 0, 2, 2};
int mv_c[6] = { -1, 1, -2, 2, -1, 1};

bool isValid(int r, int c) {
    return r < n && c < n && r >= 0 && c >= 0 && !visited[r][c];
}

void BFS() {
    q.push({0, {r1, c1}});
    visited[r1][c1] = true;

    while( !q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if( r == r2 && c ==c2 ){
            cout << cnt;
            return;
        }

        for(int i=0; i < 6; i++){
            int to_r = r + mv_r[i];
            int to_c = c + mv_c[i];
            if( isValid(to_r, to_c) ) {
                visited[to_r][to_c] = true;
                q.push({cnt+1, {to_r, to_c}});
            }
        }
    }
    cout << -1;

}


int main (){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    BFS();
}