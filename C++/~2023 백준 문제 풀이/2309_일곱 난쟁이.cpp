//
// Created by 김유리 on 2024/02/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heights(9);

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
        sum += heights[i];
    }

    sort(heights.begin(), heights.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - heights[i] - heights[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    cout << heights[k] << '\n';
                }
                return 0;
            }
        }
    }
}