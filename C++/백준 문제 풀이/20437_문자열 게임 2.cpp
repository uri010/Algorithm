//
// Created by 김유리 on 2023/11/10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, K;
string W;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> W >> K;
        vector<int> v;
        int *alphabet = new int[26];
        for (int i = 0; i < W.size(); i++) {
            alphabet[W[i] - 'a']++;
        }
        for (int i = 0; i < W.size(); i++) {
            if (alphabet[W[i] - 'a'] < K) continue;
            int cnt = 0;
            for (int j = i; j < W.size(); j++) {
                if (W[i] == W[j]) {
                    cnt++;
                }
                if (cnt == K) {
                    v.push_back(j - i + 1);
                    break;
                }
            }
        }

        sort(v.begin(), v.end());

        if (!v.empty()) {
            cout << v[0] << " " << v[v.size() - 1] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}