//
// Created by 김유리 on 2024/04/02.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> v;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    int x;
    for (int i = 0; i < M; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int left = 1, right = v[M - 1];
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            cnt += v[i] / mid;
            if (v[i] % mid != 0) cnt++;
        }

        if (cnt <= N) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
}