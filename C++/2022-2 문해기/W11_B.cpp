//
// Created by 김유리 on 2022/11/17.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, m;
int team[100002];
pair<int, int> score[100002];
int chance[100002];
int rest, ans;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(team, 0, sizeof(team));
        memset(score, 0, sizeof(score));
        memset(chance, 0, sizeof(chance));
        rest = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> team[i];
            score[team[i]].first += n - i + 1;
            score[team[i]].second = team[i];
            if (i != 1 && team[i] == 1 && team[i - 1] != team[i]) {
                rest += 1;
                chance[team[i - 1]] += 1;
            }
        }
        sort(score, score + m + 1);
        while (rest > 0) {
            if (score[m].second == 1 && score[m].first > score[m - 1].first)
                break;
            bool flag = true;
            for (int i = m; i >= 1; i--) {
                if (score[i].second == 1)
                    score[i].first += 1;
                if (flag == true && chance[score[i].second] > 0) {
                    chance[score[i].second] -= 1;
                    score[i].first -= 1;
                    flag = false;
                    rest -= 1;
                    ans += 1;
                }
            }
            sort(score, score + m + 1);
        }
        if (score[m].second == 1 && score[m].first > score[m - 1].first) {
            cout << ans << "\n";
        } else cout << -1 << "\n";
    }
}