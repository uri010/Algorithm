//
// Created by 김유리 on 2024/03/02.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') cout << " ";
        else {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i] - 'a' < 13) s[i] += 13;
                else s[i] -= 13;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] - 'A' < 13) s[i] += 13;
                else s[i] -= 13;
            }
            cout << s[i];
        }
    }
}