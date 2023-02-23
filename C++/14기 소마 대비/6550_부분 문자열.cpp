//
// Created by 김유리 on 2023/02/24.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    while (cin >> s >> t) {
        int pre = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = pre; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    cnt++;
                    pre = j + 1;
                    break;
                }
                if (j == t.size() - 1 && cnt < s.size()) {
                    cout << "No\n";
                }
            }
        }
        if (cnt == s.size()) {
            cout << "Yes\n";
        }
    }
}