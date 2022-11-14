//
// Created by 김유리 on 2022/11/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> strs;
string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string tmp;
        for (int j = i; j < s.size(); j++) {
            tmp += s[j];
        }
        strs.push_back(tmp);
    }
    sort(strs.begin(), strs.end());
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << "\n";
    }
}