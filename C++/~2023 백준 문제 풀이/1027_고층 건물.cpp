//
// Created by 김유리 on 2023/11/01.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
int heights[52];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        double maxGradient = -1000000000;

        for (int j = i + 1; j < N; j++) {
            int h = heights[j] - heights[i];
            int w = j - i;
            double g = h * 1.0 / w;

            if (g <= maxGradient) continue;

            maxGradient = g;
            cnt[i]++;
            cnt[j]++;
        }
    }
    cout << *max_element(cnt.begin(), cnt.end());

}