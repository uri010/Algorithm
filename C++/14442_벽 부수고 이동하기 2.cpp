//
// Created by 김유리 on 2022/07/20.
//
#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int map[1001][1001];
int dist[1001][1001][11];

queue<pair<int, pair<int,int>>> q;

void BFS(){

}



int main (){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    string s;
    for(int i=0; i < n; i++){
        cin >> s;
        for(int j=0;j < m; j++){
            map[i][j] = s[j] -'0';
        }
    }
    q.push({0, {0, 0}});
}