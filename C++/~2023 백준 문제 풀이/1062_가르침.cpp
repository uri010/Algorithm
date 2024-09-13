//
// Created by 김유리 on 2023/08/02.
//
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<string> str;
vector<char> v;
bool alphabet[27];
bool learned[27];
int ans;

void DFS(vector<char> comb, int r, int index, int depth) {
    if (r == 0) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            bool flag = true;
            for (int j = 4; j < str[i].size() - 4; j++) {
                if (!learned[str[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        if (ans < cnt) ans = cnt;
    } else if (depth == v.size()) {
        return;
    } else {
        comb[index] = v[depth];
        learned[comb[index] - 'a'] = true;
        DFS(comb, r - 1, index + 1, depth + 1);
        learned[comb[index] - 'a'] = false;
        DFS(comb, r, index, depth + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        str.push_back(s);
        for (int j = 4; j < s.size() - 4; j++) {
            if (s[j] == 'a' || s[j] == 'n' || s[j] == 'c' || s[j] == 't' || s[j] == 'i') continue;
            if (!alphabet[s[j] - 'a']) {
                v.push_back(s[j]);
                alphabet[s[j] - 'a'] = true;
            }
        }
    }
    if (K < 5) {
        cout << 0;
        return 0;
    }
    if (K - 5 > v.size()) {
        cout << N;
        return 0;
    }
    K -= 5;
    vector<char> comb(K);
    learned['a' - 'a'] = true;
    learned['n' - 'a'] = true;
    learned['c' - 'a'] = true;
    learned['t' - 'a'] = true;
    learned['i' - 'a'] = true;
    DFS(comb, K, 0, 0);
    cout << ans;
}