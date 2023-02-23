#include <iostream>
using namespace std;

double cakes[20];
bool selected[20];
int bound;
double total;
int n;
int ans;

void check(){
    total =0;
    for(int i=0; i < n; i++){
        if( selected[i]){
            total = total + (1/cakes[i]);
        }
    }
    if( total >= 0.99 && total <= 1.01) {
        ans++;
    }
}


void DFS(int idx, int cnt){
    if(cnt == bound ){
        check();
        return;
    }
    for(int i= idx; i < n; i++ )
    {
        if(selected[i] ==true) continue;
        selected[i] = true;
        DFS(i, cnt+1);
        selected[i] = false;
    }
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i < n;i++){
        cin >> cakes[i];
    }
    for(bound =1; bound <= n;bound++){
        DFS(0, 0);
    }
    cout << ans ;
}