//
// Created by 김유리 on 2022/05/25.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, a,b,m,x,y;
vector<vector<int>> map(100);
bool visited[100];
queue<pair<int,int>> q;

void BFS(){
    while(!q.empty()){
        int p = q.front().first;
        int cnt = q.front().second;
        visited[p] = true;
        q.pop();

        if( p == b) {cout << cnt << "\n"; return;}

        for(int i=0; i <map[p].size(); i++) {
            if (!visited[map[p][i]]) {
                q.push({map[p][i],cnt+1});
                visited[map[p][i]] = true;
            }
        }
    }
    cout << -1 << "\n";


}

int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> a >> b;
    cin >> m;
    for(int i=0; i < m;i++){
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    q.push({a,0});
    BFS();
}
