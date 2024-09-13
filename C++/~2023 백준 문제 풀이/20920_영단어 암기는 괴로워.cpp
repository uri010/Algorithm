//
// Created by 김유리 on 2023/10/22.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> m;
vector<string> voca;

bool compare(string a, string b) {
    if (a.size() == b.size() && m[a] == m[b]) {
        return a < b;
    } else if (m[a] == m[b]) {
        return a.size() > b.size();
    }
    return m[a] > m[b];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str.size() < M) continue;
        if (m.find(str) == m.end()) {
            m[str] = 0;
            voca.push_back(str);
        }
        m[str]++;
    }
    sort(voca.begin(), voca.end(), compare);
    for (int i = 0; i < voca.size(); i++) {
        cout << voca[i] << "\n";
    }
}