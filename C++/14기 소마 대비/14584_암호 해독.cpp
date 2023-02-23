//
// Created by 김유리 on 2023/02/24.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int n;
    cin >> n;
    string words[21];
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < str.size(); j++) {
            if (str[j] + 1 > 122) {
                str[j] = str[j] - 25;
            } else {
                str[j] = str[j] + 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (str.find(words[j]) != std::string::npos) {
                cout << str;
                return 0;
            }
        }
    }
}