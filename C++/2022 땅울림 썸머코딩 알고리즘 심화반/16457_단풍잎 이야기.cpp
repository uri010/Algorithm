//
// Created by 김유리 on 2022/08/11.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m, k, a;
int quest[102];
int ans;

void CountQuest(int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if ((quest[i] & x) == quest[i]) {
            cnt++;
        }
    }
    ans = max(ans, cnt);
}


void Solve(int i, int d, int cnt) {
    if (cnt == n) {
        CountQuest(i);
        return;
    } else if (d == 2 * n + 1) return;
    else {
        Solve(i, d + 1, cnt);
        i = i | (1 << d);
        Solve(i, d + 1, cnt + 1);
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a;
            quest[i] = quest[i] | (1 << a);
        }
    }
    Solve(0, 1, 0);

    cout << ans;
}