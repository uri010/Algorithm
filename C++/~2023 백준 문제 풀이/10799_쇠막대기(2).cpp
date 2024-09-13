//
// Created by 김유리 on 2023/07/06.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    s = " " + s;

    int cnt = 0, stick = 0;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }

        if (s[i - 1] == '(' && s[i] == '(') {
            stick++;
        }

        if (s[i - 1] == '(' && s[i] == ')') {
            ans += stick + cnt;
            stick = 0;
        }
    }
     cout << ans;
}