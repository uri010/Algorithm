#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, k;
int map[2][200001];
bool visited[2][200001];
queue<pair<int, pair<int,int>>> q;//{cnt, idx, map1인지 map2인지}


void BFS(){
    while(!q.empty()){
        int cnt = q.front().first;
        int idx = q.front().second.first;
        int map_num = q.front().second.second;
        q.pop();
        if( idx >= n ){
            cout << 1;
            return;
        }
        cnt++;
        if (map[map_num][idx+1] == 1 && (idx+1) >= cnt  && !visited[map_num][idx+1]){
            visited[map_num][idx+1] = true;
            q.push({ cnt, {idx+1, map_num}});
        }
        if( map[map_num][idx-1] == 1 &&(idx-1) >= cnt && !visited[map_num][idx-1]) {
            visited[map_num][idx-1] = true;
            q.push({ cnt, {idx-1, map_num}});
        }
        if(map_num == 0) {
            map_num = 1;
        }
        else map_num = 0;
        if( map[map_num][idx+k] ==1 && idx+k >= cnt&& !visited[map_num][idx+k]) {visited[map_num][idx+k] = true;
            q.push({cnt, {idx+k, map_num}});
        }
    }
    cout << 0;
}

int main (){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0; i< n+k; i++){
        map[0][i] = 1;
        map[1][i] = 1;
    }
    string str;
    cin >> str;
    for(int i=0; i < n; i ++){
        map[0][i] = str[i]-'0';
    }
    cin >> str;
    for(int i=0; i < n; i ++){
        map[1][i] =str[i] -'0';
    }
    q.push({ 0, {0,0}});
    BFS();

}