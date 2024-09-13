//
// Created by 김유리 on 2024/03/25.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, mp, mf, ms, mv;
int x;
int arr[16][5];
int total[5];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            if (j != 4) total[j] += arr[i][j];
        }
    }
    if (total[0] < mp || total[1] < mf || total[2] < ms || total[3] < mv) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    int bitMask = 1;
    for (int i = 0; i < N; i++) {
        bitMask *= 2;
    }

    int ans = 1000000000;
    vector<pair<int, int>> idx;
    while ((cnt & bitMask) != bitMask) {
        memset(total, 0, sizeof(total));
        for (int i = 0; i < N; i++) {
            if ((cnt & (1 << i)) == (1 << i)) {
                for (int j = 0; j < 5; j++) {
                    total[j] += arr[i + 1][j];
                }
            }
        }
        if (total[0] >= mp && total[1] >= mf && total[2] >= ms && total[3] >= mv) {
            idx.push_back({total[4], cnt});
        }
        cnt++;
    }
    sort(idx.begin(), idx.end());
    ans = idx[0].first;

    cout << idx[0].first << "\n";
    map<int, vector<vector<int>>> ret;

    for (int i = 0; i < idx.size(); i++) {
        if (idx[i].first > ans) break;
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            if ((idx[i].second & (1 << j)) == (1 << j)) {
                tmp.push_back(j + 1);
            }
        }
        ret[ans].push_back(tmp);
    }

    sort(ret[ans].begin(), ret[ans].end());
    for (auto r: ret[ans][0]) {
        cout << r << " ";
    }
}