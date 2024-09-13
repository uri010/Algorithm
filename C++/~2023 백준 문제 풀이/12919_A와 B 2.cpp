//
// Created by 김유리 on 2024/01/17.
//
#include <iostream>
#include <algorithm>

using namespace std;

string s, t;

void Solve(string str) {
    if (str == s) {
        cout << 1;
        exit(0);
    }
    if (str.length() == 0) return;

    string tmp = str;
    if (str[str.length() - 1] == 'A') {
        tmp.erase(str.length() - 1, 1);
        Solve(tmp);
    }
    if (str[0] == 'B') {
        str.erase(0, 1);
        reverse(str.begin(), str.end());
        Solve(str);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s >> t;
    Solve(t);
    cout << 0;
}