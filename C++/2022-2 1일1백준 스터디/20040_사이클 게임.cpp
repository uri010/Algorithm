//
// Created by 김유리 on 2022/11/02.
//
#include <iostream>

using namespace std;

int n, m, x, y;
int par[500002];
int ans;

int Find(int a) {
    if (par[a] == a)
        return a;

    return par[a] = Find(par[a]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    int flag = 1;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (flag) {
            int par_x = Find(x);
            int par_y = Find(y);
            if (par_x == par_y) {
                ans = i + 1;
                flag = 0;
            } else {
                par[par_y] = par_x;
            }
        }
    }
    cout << ans;
}