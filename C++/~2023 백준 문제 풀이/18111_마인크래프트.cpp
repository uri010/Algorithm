//
// Created by 김유리 on 2023/07/28.
//
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, B;
int arr[501][501];
int height[257];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            for (int k = 1; k <= arr[i][j]; k++) {
                height[k]++;
            }
        }
    }

    int ans1 = 2100000000;
    int ans2 = 0;
    for (int h = 0; h <= 256; h++) {
        int time = 0;
        int inven = B;

        for (int k = 1; k <= h; k++) {
            inven -= (N * M - height[k]);
            time += (N * M - height[k]);
        }
        for (int k = h + 1; k <= 256; k++) {
            inven += height[k];
            time += (height[k] * 2);
        }
        if (inven < 0) continue;
        if (ans1 >= time) {
            ans1 = time;
            ans2 = h;
        }
    }
    cout << ans1 << " " << ans2;
}