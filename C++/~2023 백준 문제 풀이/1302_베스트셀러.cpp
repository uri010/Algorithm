//
// Created by 김유리 on 2023/07/03.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if( a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    string s;
    map<string, int> m;
    cin >> N;
    while (N--) {
        cin >> s;
        if (m.find(s) != m.end()) {
            m[s]++;
        } else {
            m.insert({s, 1});
        }
    }
    vector<pair<string, int>> v;
    for (auto iter: m) {
         v.push_back(iter);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first;
}