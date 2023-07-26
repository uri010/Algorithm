//
// Created by 김유리 on 2023/07/27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N, x;
vector<int> v;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do {
        int tmp = 0;
        for (auto it = v.begin(); it != --v.end(); it++) {
            tmp = tmp + abs(*it - *(++it));
            --it;
        }
        if (ans < tmp) ans = tmp;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}