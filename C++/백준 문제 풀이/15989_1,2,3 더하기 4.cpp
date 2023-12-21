//
// Created by 김유리 on 2023/12/21.
//
#include <iostream>

using namespace std;

int T, n;
int ans[10001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    ans[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 10000; j++) {
            ans[j] = ans[j] + ans[j - i];
        }
    }

    cin >> T;
    while (T--) {
        cin >> n;
        cout << ans[n] << "\n";
    }
}