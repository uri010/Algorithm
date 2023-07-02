//
// Created by 김유리 on 2023/07/03.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a > b;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string name, log;
    map<string, bool> m;
    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> log;
        bool flag = false;
        if (log == "enter") flag = true;

        if (m.find(name) == m.end()) {
            m.insert({name, flag});
        } else {
            m[name] = flag;
        }
    }

    for (auto iter: m) {
        if (iter.second) v.push_back(iter.first);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
}