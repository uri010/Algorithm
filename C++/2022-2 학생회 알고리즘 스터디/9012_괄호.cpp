//
// Created by 김유리 on 2022/09/19.
//
#include <iostream>

using namespace std;

int t;
string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> s;
        int open = 0;
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open > 0) {
                    open--;
                } else {
                    cout << "NO\n";
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            if (open == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}