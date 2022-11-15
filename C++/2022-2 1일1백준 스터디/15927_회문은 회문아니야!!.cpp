//
// Created by 김유리 on 2022/11/14.
//
#include <iostream>

using namespace std;

string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s;
    int flag = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            cout << s.size();
            return 0;
        } else if (s[i] != s[i + 1]) {
            flag = 1;
        }
    }
    if (flag) cout << s.size() - 1;
    else cout << -1;
}