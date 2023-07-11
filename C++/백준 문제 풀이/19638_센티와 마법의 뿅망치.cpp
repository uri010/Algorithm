//
// Created by 김유리 on 2023/07/11.
//
#include <iostream>
#include <queue>

using namespace std;

int N, H, T;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> H >> T;
    int h;
    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        cin >> h;
        q.push(h);
    }

    for (int i = 0; i < T; i++) {
        int cur = q.top();

        if (cur < H) {
            cout << "YES\n" << i;
            return 0;
        }
        if (cur > 1) {
            q.pop();
            q.push(cur / 2);
        }
    }
    if (q.top() < H)
        cout << "YES\n" << T;
    else
        cout << "NO\n" << q.top();
}