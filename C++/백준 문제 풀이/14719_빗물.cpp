//
// Created by 김유리 on 2023/10/24.
//
#include <iostream>

using namespace std;

int H, W;
int map[501][501];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    int height;
    for (int i = 0; i < W; i++) {
        cin >> height;
        for (int j = 0; j < height; j++) {
            map[j][i] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        bool flag = false;
        int cnt = 0;
        for (int j = 0; j < W; j++) {
            if (flag) {
                if (j != W - 1 && map[i][j] == 0) {
                    cnt++;
                } else if (map[i][j] == 1) {
                    ans += cnt;
                    cnt = 0;
                }
            } else if (map[i][j] == 1) {
                flag = true;
            }
        }
    }
    cout << ans;
}
