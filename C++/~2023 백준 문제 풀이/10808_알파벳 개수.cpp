//
// Created by 김유리 on 2024/02/27.
//
#include <iostream>

using namespace std;

int alphabet[26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'a']++;
    }
    for(int i=0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
}