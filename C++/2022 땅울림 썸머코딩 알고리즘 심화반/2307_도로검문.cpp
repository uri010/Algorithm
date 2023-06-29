//
// Created by 김유리 on 2022/08/03.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, t;
vector<pair<int,int>> map[1002];

int main (){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0; i <m; i++){
        cin >> a >> b >> t;
        map[a].push_back({b, t});
        map[b].push_back({a, t});
    }

}