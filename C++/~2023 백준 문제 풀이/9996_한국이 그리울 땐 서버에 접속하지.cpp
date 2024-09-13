//
// Created by 김유리 on 2024/02/27.
//
#include <iostream>
#include <vector>

using namespace std;
int patternSize = 0;

vector<string> split(string s) {
    vector<string> words;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            words.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
            patternSize++;
        }
    }
    if (tmp != "") {
        words.push_back(tmp);
    }
    return words;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string p;
    cin >> p;
    vector<string> pattern = split(p);


    string s[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < N; i++) {
        int idx = 0;
        int cnt = 0;

        if (patternSize > s[i].size()) {
            cout << "NE\n";
            continue;
        }

        bool isFirst = true;
        for (int j = 0; j < pattern[0].size(); j++) {
            if (pattern[0][j] != s[i][j]) {
                cout << "NE\n";
                isFirst = false;
                break;
            }
        }
        if (!isFirst) continue;

        bool isLast = true;
        for (int j = 0; j < pattern[pattern.size() - 1].size(); j++) {
            if (pattern[pattern.size() - 1][j] != s[i][s[i].size() - pattern[pattern.size() - 1].size() + j]) {
                cout << "NE\n";
                isLast = false;
                break;
            }
        }
        if (!isLast) continue;

        if (pattern.size() == 2) {
            cout << "DA\n";
            continue;
        }

        int patternIdx = 1;
        for (int j = pattern[0].size(); j < s[i].size(); j++) {
            if (pattern[patternIdx][0] == s[i][j]) {
                bool isSame = true;
                for (int k = 1; k < pattern[patternIdx].size(); k++) {
                    if (pattern[patternIdx][k] != s[i][j + k]) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    patternIdx++;
                    j += pattern[patternIdx].size() - 1;
                }
            }
            if (patternIdx == pattern.size() - 1) {
                cout << "DA\n";
                break;
            }
        }
    }
}