//
// Created by 김유리 on 2023/08/01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, A;
vector<pair<int, int>> kit;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A;
        kit.push_back({i, A});
    }
    sort(kit.begin(), kit.end());
    int ans = 0;
    do {
        int weight = 500;
        bool flag = true;
        for (auto it = kit.begin(); it != kit.end(); it++) {
            weight = weight - K + it->second;
            if (weight < 500) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    } while (next_permutation(kit.begin(), kit.end()));
    cout << ans;

}