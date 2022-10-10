//
// Created by 김유리 on 2022/10/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, k;
int disk[101];
vector<pair<int, pair<int, int>>> process;
int ans[101];

void hanoi(int x, int from, int tmp, int to) {
    if (x == 1) {
        int cnt = disk[x];
        while (cnt--) {
            process.push_back({x, {from, to}});
        }
        return;
    } else {
        hanoi(x - 1, from, to, tmp);
        int cnt = disk[x];
        while (cnt--) {
            process.push_back({x, {from, to}});
        }
        hanoi(x - 1, tmp, from, to);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        memset(disk, 0, sizeof(disk));
        memset(ans, 0, sizeof(ans));
        process.clear();
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            disk[i] += x;
        }
        cin >> k;
        hanoi(n, 1, 2, 3);
        for (int i = 0; i < k; i++) {
            int num = process[i].first;
            if (process[i].second.first == 2) {
                ans[num]--;
            } else if (process[i].second.second == 2) {
                ans[num]++;
            }
        }
        int flag = 0;
        for (int i = 0; i < 101; i++) {
            while (ans[i] > 0) {
                cout << i << " ";
                ans[i]--;
                flag = 1;
            }
        }
        if (flag == 0) cout << 0;
        cout << "\n";
    }

}