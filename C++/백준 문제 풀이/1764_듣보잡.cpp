//
// Created by 김유리 on 2023/07/10.
//
#include <iostream>
#include <map>

using namespace std;

int N, M;
string name;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    map<string, bool> m;
    while (N--) {
        cin >> name;
        m.insert({name, false});
    }
    int cnt = 0;
    while (M--) {
        cin >> name;
        if (m.find(name) != m.end()) {
            m[name] = true;
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (auto iter: m) {
        if (iter.second == true)
            cout << iter.first << "\n";
    }
}