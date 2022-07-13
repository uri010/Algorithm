#include <iostream>
#include <queue>
using namespace std;

class Node{
public :
    int x1;
    int y1;
    int x2;
    int y2;
    int cnt;
    Node(int x1, int y1, int x2, int y2, int cnt){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->cnt = cnt;
    }
};
char map[21][21];
int n, m;

int mv_x[4] = {1,-1, 0,0};
int mv_y[4] = {0,0,1,-1};

queue<Node> q;

void BFS(){
    q.push(Node())
}


int main (){
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> m;

    int x1 =-1, x2= -1,y1= -1, y2=-1;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> map[i][j];
            if( map[i][j] == 'o'){
                if( x1 ==-1 && y1==-1){
                    x1 = i;
                    y1 = j;
                }else{
                    x2 =i;
                    y2 = j;
                }
            }
        }
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){

        }
    }
}