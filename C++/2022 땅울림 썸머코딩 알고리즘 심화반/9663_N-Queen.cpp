//
// Created by 김유리 on 2022/08/12.
//
#include <iostream>

using namespace std;

int n;
bool map[16][16];
int width, length, diag1, diag2;
int ans;

bool isValid(int i, int j) {
    if ((width & (1 << i)) != 0) return false;
    if ((length & (1 << j)) != 0) return false;
    if ((diag1 & (1 << i + j)) != 0) return false;
    while (i != 0 && j != 0) {
        i--;
        j--;
    }
    if (i == 0)
        if ((diag2 & (1 << j + n)) != 0) return false;
        else if ((diag2 & (1 << i)) != 0) return false;

    return true;
}

void Solve(int i, int j, int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    if (i == n) return;

    if (isValid(i, j)) {
        int tmp_width = width;
        int tmp_length = length;
        int tmp_diag1 = diag1;
        int tmp_diag2 = diag2;
        width = width | (1 << i);
        length = length | (1 << j);
        diag1 = diag1 | (1 << i + j);
        int ni = i;
        int nj = j;
        while (ni != 0 && nj != 0) {
            ni--;
            nj--;
        }
        if (ni == 0)
            diag2 = diag2 | (1 << (nj + n));
        else
            diag2 = diag2 | (1 << ni);

        if (j + 1 < n)
            Solve(i, j + 1, cnt + 1);
        else
            Solve(i + 1, 0, cnt + 1);

        width = tmp_width;
        length = tmp_length;
        diag1 = tmp_diag1;
        diag2 = tmp_diag2;
    }
    else{
        if (j + 1 < n)
            Solve(i, j + 1, cnt);
        else
            Solve(i + 1, 0, cnt);
    }
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    Solve(0, 0, 0);
    cout << ans;

}