//
// Created by 김유리 on 2022/05/13.
//
#include <iostream>
#include <queue>
using namespace std;

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int n;
    cin >> n;
    for(int i=0; i <n;i++){
        int x;
        cin >> x;
        if( x!= 0 ) {
            if( x>0) pq.push({x, 1});
            else pq.push({-x, -1});
        }
        else {
            if( pq.size() == 0) cout << 0 << "\n";
            else {
                if (pq.top().second == 1) cout << pq.top().first << "\n";
                else cout << -pq.top().first << "\n";
                pq.pop();
            }
        }
    }
}