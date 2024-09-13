//
// Created by 김유리 on 2024/03/06.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int arr[1001];
map<int, pair<int, int>> m;

static bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first > b.second.first;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (m.find(arr[i]) != m.end()) {
            m[arr[i]].first++;
        } else {
            m.insert({arr[i], {1, i}});
        }
    }
    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        while (v[i].second.first--) {
            cout << v[i].first << " ";
        }
    }
}