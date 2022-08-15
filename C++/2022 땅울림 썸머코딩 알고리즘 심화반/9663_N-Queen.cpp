//
// Created by 김유리 on 2022/08/12.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
int length, diag1, diag2;
int ans;

bool isValid(int i, int j) {
    if ((diag1 & (1 << (i + j))) != 0) return false;
    if (i - j > 0) {
        i = i - j;
        j = 0;
    } else {
        j = j - i;
        i = 0;
    }

    if (i == 0) {
        if ((diag2 & (1 << (j + n))) != 0) return false;
    } else if (j == 0) {
        if ((diag2 & (1 << i)) != 0) return false;
    }
    return true;
}

vector<int> AvailableNum() {
    vector<int> tmp;
    for (int j = 0; j < n; j++) {
        if ((length & (1 << j)) == 0)
            tmp.push_back(j);
    }
    return tmp;
}

void Solve(int i, int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    if (i == n) return;
    int tmp_length = length;
    int tmp_diag1 = diag1;
    int tmp_diag2 = diag2;

    vector<int> x = AvailableNum();
    for (int j: x) {
        if (isValid(i, j)) {
            length = length | (1 << j);
            diag1 = diag1 | (1 << (i + j));
            int ni = i;
            int nj = j;
            if (ni - nj > 0) {
                ni = ni - nj;
                nj = 0;
            } else {
                nj = nj - ni;
                ni = 0;
            }
            if (ni == 0)
                diag2 = diag2 | (1 << (nj + n));
            else
                diag2 = diag2 | (1 << ni);

            Solve(i + 1, cnt + 1);

            length = tmp_length;
            diag1 = tmp_diag1;
            diag2 = tmp_diag2;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    Solve(0, 0);
    cout << ans;
}