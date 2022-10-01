//
// Created by 김유리 on 2022/10/01.
//
#include <iostream>

using namespace std;

int n;
int map[3000][3000];
int ans_0, ans_1, ans_m;

bool AllNum(int i, int j, int size) {
    bool flag_1 = false, flag_0 = false, flag_m = false, flag_all = true;
    for (int a = i; a < i + size; a++) {
        for (int b = j; b < j + size; b++) {
            if (map[a][b] == 1) {
                if (flag_0 || flag_m) {
                    flag_all = false;
                    break;
                } else if (!flag_1) {
                    flag_1 = true;
                }
            } else if (map[a][b] == 0) {
                if (flag_1 || flag_m) {
                    flag_all = false;
                    break;
                } else if (!flag_0) {
                    flag_0 = true;
                }
            } else {
                if (flag_0 || flag_1) {
                    flag_all = false;
                    break;
                } else if (!flag_m) {
                    flag_m = true;
                }
            }
        }
    }
    if (flag_all) {
        if (flag_0) ans_0++;
        else if (flag_1) ans_1++;
        else ans_m++;
        return true;
    }
    return false;
}

void Solve(int i, int j, int size) {

    if (!AllNum(i, j, size)) {
        int prev_size = size;
        size /= 3;
        for (int a = i; a < i + prev_size; a += size) {
            for (int b = j; b < j + prev_size; b += size) {
                Solve(a, b, size);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    Solve(0, 0, n);
    cout << ans_m << "\n" << ans_0 << "\n" << ans_1 << "\n";

}