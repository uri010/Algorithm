//
// Created by 김유리 on 2022/08/16.
//
#include <iostream>

using namespace std;

int n, col[17], dig1[32], dig2[32], ans;

void sol(int i) {
    if (i == n) {
        ans++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (col[j] || dig1[j + i] || dig2[j - i + n - 1])
            continue;
        col[j] = dig1[j + i] = dig2[j - i + n - 1] = 1;
        sol(i + 1);
        col[j] = dig1[j + i] = dig2[j - i + n - 1] = 0;

    }
}

int main() {
    cin >> n;
    sol(0);
    cout << ans << "\n";
}