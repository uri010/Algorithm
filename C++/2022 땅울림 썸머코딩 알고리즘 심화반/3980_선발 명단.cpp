//
// Created by 김유리 on 2022/09/06.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, x;
int selected;
int ans;

vector<pair<int, int>> player[12];

void Solve(int i, int cnt, int total) {
    if (cnt >= 11 ) {
        ans = max(ans, total);
        return;
    }
    if (i >= 11)
        return;

    for(int j=0;j <player[i].size(); j++) {
        auto p = player[i][j];
        if ((selected & (1 << p.first)) == 0) {
            int tmp = selected;
            selected = selected | (1 << p.first);
            total += p.second;
            Solve(i + 1, cnt + 1, total);
            selected = tmp;
            total -= p.second;
        }
    }
}

void input() {
    for (int i = 0; i < 11; i++) {
        player[i].clear();
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> x;
            if (x != 0) {
                player[j].push_back({i, x});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> c;
    while (c--) {
        input();
        ans =0;
        Solve(0, 0, 0);
        cout << ans << "\n";
    }

}