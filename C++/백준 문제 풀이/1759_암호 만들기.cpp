//
// Created by 김유리 on 2023/07/29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char x;
vector<char> v;


void DFS(vector<char> comb, int r, int index, int depth) {
    if (r == 0) {
        int cons = 0, vowel = 0;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 'a' || comb[i] == 'e' || comb[i] == 'i' || comb[i] == 'o' || comb[i] == 'u')
                cons++;
            else vowel++;
        }
        if (cons >= 1 && vowel >= 2) {
            for (int i = 0; i < comb.size(); i++)
                cout << comb[i];
            cout << endl;
        }
    } else if (depth == v.size()) {
        return;
    } else {
        comb[index] = v[depth];
        DFS(comb, r - 1, index + 1, depth + 1);

        DFS(comb, r, index, depth + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> L >> C;
    while (C--) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    vector<char> comb(L);
    DFS(comb, L, 0, 0);
}