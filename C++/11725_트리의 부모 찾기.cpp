//
// Created by 김유리 on 2022/05/19.
//
#include <iostream>
#include <vector>
using namespace std;

int arr[100001];
bool visited[100001];
vector<int> v[100001];

void DFS(int n ) {
    visited[n] = true;
    for(int i=0; i <v[n].size() ;i++){
        if( !visited[v[n][i]]) {
            arr[v[n][i]] = n;
            DFS(v[n][i]);
        }

    }
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);



    int n;
    cin >> n;
    for(int i=0;i <n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    for(int i=2; i <=n;i++){
        cout << arr[i] << "\n";
    }
}