//
// Created by 김유리 on 2022/08/01.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;


int t, f;
pair<int, int> par[200002];

int Find(int x) {
    if (par[x].first == x)
        return x;

    return par[x].first = Find(par[x].first);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);


    cin >> t;
    while (t--) {
        map<string, int> friends;
        for (int i = 1; i <= 200001; i++) {
            par[i] = {i, 1};
        }
        cin >> f;

        string a, b;
        int x, y, x_cnt, y_cnt;
        int idx = 0;

        for (int i = 0; i < f; i++) {
            cin >> a >> b;
            if (!friends.count(a)) {
                idx++;
                friends.insert({a, idx});
            }
            if (!friends.count(b)) {
                idx++;
                friends.insert({b, idx});
            }

            x = Find(friends.at(a));
            x_cnt = par[x].second;
            y = Find(friends.at(b));
            y_cnt = par[y].second;
            if (x != y) {
                par[y].first = x;
                par[y].second = x_cnt + y_cnt;
                par[x].second = x_cnt + y_cnt;
            }
            //출력 형식 주의...
            cout << par[x].second << "\n";
        }
    }
}