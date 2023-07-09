//
// Created by 김유리 on 2023/07/09.
//
#include <iostream>
#include <stack>

using namespace std;

int N, A, T, x;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    stack<pair<int, int>> st;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 1) {
            cin >> A >> T;
            st.push({A, T});
        }
        if (!st.empty()) {
            int score = st.top().first;
            int time = st.top().second;
            st.pop();

            time--;
            if (time == 0) {
                ans += score;
            } else {
                st.push({score, time});
            }
        }
    }
    cout << ans;
}