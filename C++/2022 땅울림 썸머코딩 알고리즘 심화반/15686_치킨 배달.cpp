//
// Created by 김유리 on 2022/08/23.
//
#include <iostream>
#include <vector>
#include <cmath>

#define INF 100000000

using namespace std;

int n, m;
int map[51][51];
int ans = INF;
vector<pair<int, int>> store;
vector<pair<int, int>> comb;
vector<pair<int, int>> home;

int Check() {
    int total = 0;
    for (int i = 0; i < home.size(); i++) {
        int min_dis = INF;
        for (int j = 0; j < comb.size(); j++) {
            int tmp = abs(home[i].first - comb[j].first) + abs(home[i].second - comb[j].second);
            min_dis = min(min_dis, tmp);
        }
        total += min_dis;
    }
    return total;
}

void Select(int x, int cnt, int r) {
    if (cnt >= r) {
        ans = min(ans, Check());
        return;
    }
    for (int i = x; i < store.size(); i++) {
        comb.push_back({store[i].first, store[i].second});
        Select(i + 1, cnt + 1, r);
        comb.pop_back();
        Select(i + 1, cnt, r);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                home.push_back({i, j});
            else if (map[i][j] == 2)
                store.push_back({i, j});
        }
    }
    Select(0, 0, m);
    cout << ans;

}