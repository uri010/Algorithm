//
// Created by 김유리 on 2023/07/10.
//
#include <iostream>
#include <map>

using namespace std;

int N;
string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    map<string, int> m;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "ENTER") {
            m.clear();
        } else {
            if (m.find(s) == m.end()) {
                m.insert({s, 1});
                ans++;
            }
        }
    }
    cout << ans;
}