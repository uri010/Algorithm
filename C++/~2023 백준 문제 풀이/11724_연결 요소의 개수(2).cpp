//
// Created by 김유리 on 2022/05/23.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(1001);
bool visited[1001];

void DFS(int a){
    visited[a] = true;

    for(int i=0; i < map[a].size(); i++){
        if( !visited[map[a][i]] ){
            DFS(map[a][i]);
        }
    }
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;


    for(int i=0; i <m;i++){
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    int ans =0;
    for(int i=1; i <= n;i++){
        if( !visited[i] ) {
            DFS(i);
            ans++;
        }
    }
    cout << ans;



}