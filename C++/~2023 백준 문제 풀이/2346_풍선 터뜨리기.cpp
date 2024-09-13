//
// Created by 김유리 on 2023/07/05.
//
#include <iostream>
#include <queue>

using namespace std;

deque<pair<int, int>> dq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, x;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        dq.push_back({i, x});
    }

    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();
        cout << cur.first << " ";
        if (dq.empty()) break;

        if (cur.second > 0) {
            for (int i = 0; i < cur.second - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < -cur.second; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

