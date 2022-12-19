//
// Created by 김유리 on 2022/11/02.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int han;
int t, n, m, k;
int x, y;
int dist[1001];
vector<int> v[1001];

void bfs(){
    queue<pair<int,int>> q;
    q.push({han, 0});
    dist[han] = 0;
    while( !q.empty()){
        int now = q.front().first;
        int cost= q.front().second;
        q.pop();
        for( int next : v[now]) {
            if( dist[next] == -1) {
                dist[next] = cost + 1;
                q.push({next, cost+1});
            }
        }
    }

}

int main (){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while( t--) {
        cin >> n >> m >> k;
        for(int i=0; i <1001; i ++){
            v[i].clear();
        }
        for(int i=0;i <1001; i++){
            dist[i] = -1;
        }
        int min_height = 1000000001;
        for(int i=0; i <n; i++){
            cin >> x;
            if( min_height > x) {
                han = i;
                min_height = x;
            }
        }
        for(int i=0; i <m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs();
        for(int i=0;i <k; i++){
            cin >> x;
            cout << dist[x] << "\n";
        }
    }
}
