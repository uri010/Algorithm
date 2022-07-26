//
// Created by 김유리 on 2022/07/22.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> party;
bool party_know[52];
bool know[52];

bool solve() {
    int flag = 0;
    for (int i = 0; i < m; i++) {
        if (party_know[i]) {
            for (int x: party[i]) {
                if (know[x]) continue;
                know[x] = true;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (party_know[i]) continue;
        for (int x: party[i]) {
            if (know[x]) {
                party_know[i] = true;
            }
        }
    }
    return flag;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    party.resize(m + 2);

    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        know[b] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            party[i].push_back(b);
            if (know[b]) {
                party_know[i] = true;
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < m; i++) {
        if (party_know[i]) {
            for (int x: party[i]) {
                know[x] = true;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (party_know[i]) continue;
        for (int x: party[i]) {
            if (know[x]) {
                party_know[i] = true;
                flag = 1;
            }
        }
    }
    while (flag) {
        flag = solve();
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (!party_know[i])cnt++;
    }
    cout << cnt;
}