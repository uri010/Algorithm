//
// Created by 김유리 on 2024/03/07.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool com(string a, string b) {
    if (a.size() < b.size())
        return true;
    else if (a.size() == b.size()) {
        if (a < b) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string s;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        cin >> s;
        string tmp = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                tmp += s[j];
            } else {
                if (tmp != "") {
                    v.push_back(tmp);
                }
                tmp = "";
            }
        }
        if (tmp != "") v.push_back(tmp);
    }

    vector<string> ans;
    for (int i = 0; i < v.size(); i++) {
        bool flag = false;
        string ansStr;
        if (v[i] == "") continue;

        for (int j = 0; j < v[i].size(); j++) {
            if (!flag) {
                if (v[i][j] == '0') {
                    continue;
                } else {
                    flag = true;
                    ansStr += v[i][j];
                }
            } else {
                ansStr += v[i][j];
            }
        }

        if (!flag) {
            if (ansStr.size() == 0) {
                char ch = '0';
                ansStr += ch;
                ans.push_back(ansStr);
                continue;
            }
        }
        ans.push_back(ansStr);
    }

    sort(ans.begin(), ans.end(), com);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}