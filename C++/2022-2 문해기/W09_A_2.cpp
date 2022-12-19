//
// Created by 김유리 on 2022/12/08.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, k;
int a, b;
queue<pair<int,int>> q;
int map[1002];
int dist[1002];
int visited[1002];
vector<int> v[1002];

void BFS() {
    while( !q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        dist[now] = cnt;
        q.pop();
        for(int next : v[now]){
            if( !visited[next]){
                visited[next] = true;
                q.push({next, cnt+1});
            }
        }
    }
}

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while( t-- ) {
        cin >> n >>m >> k;
        for(int i=0; i <1002; i++){
            dist[i] = -1;
        }
        memset(visited, false, sizeof(visited));
        for(int i=0; i <1002; i++){
            v[i].clear();
        }
        int min_city = 0, min_height = 1000000000;
        for (int i = 0; i < n; i++) {
            cin >> map[i];
            if (map[i] < min_height) {
                min_height = map[i];
                min_city = i;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        q.push({min_city, 0});
        visited[min_city] = true;
        BFS();
        for (int i = 0; i < k; i++) {
            cin >> a;
            cout << dist[a] << "\n";
        }
    }

}