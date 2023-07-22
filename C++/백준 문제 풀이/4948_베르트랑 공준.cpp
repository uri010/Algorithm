//
// Created by 김유리 on 2023/07/22.
//
#include <iostream>
#include <cmath>

using namespace std;

int t, n;
int prime[300000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    prime[0] = prime[1] = true;
    for (int i = 2; i <= sqrt(2 * 123456); i++) {
        if (prime[i] == false) {
            for (int j = i + i; j <= 2 * 123456; j += i) {
                prime[j] = true;
            }
        }
    }

    while (cin >> n && n != 0) {
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (!prime[i]) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}