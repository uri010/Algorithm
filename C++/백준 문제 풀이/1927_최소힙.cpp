//
// Created by 김유리 on 2022/05/14.
//
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int n;

int main (){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0; i < n;i++){
        int x;
        cin >> x;
        if( x==0 ) {
            if( pq.size()==0 ) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}
