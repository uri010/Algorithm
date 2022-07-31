//
// Created by 김유리 on 2022/07/30.
//
#include <iostream>
#include <vector>
using namespace std;


int n, m, x, y;
int cost[1002][1002];
int par[1002];
vector<pair<int,int>> v;

int Find(int a) {
    if (a == par[a])
        return a;

    return par[a] = Find(par[a]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        par[x] = 1;
        par[y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
    x =0;
    for (int i = 1; i <= n; i++) {
        int min_cost = 100000000;
        int p1, p2;
        if (par[i] == 1)continue;
        else {
            for (int j = 2; j <= n; j++) {
                if( i==j ) continue;
                if( min_cost > cost[i][j]) {
                    min_cost = cost[i][j];
                    p1 = i;
                    p2 =j;
                }
            }
            par[i] = 1;
            x += min_cost;
            v.push_back({p1, p2});
        }
    }
    cout << x << " " << v.size() << "\n";
    for(int i=0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }


}