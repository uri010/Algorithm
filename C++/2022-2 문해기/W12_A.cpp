//
// Created by 김유리 on 2022/11/21.
//
#include <iostream>
using namespace std;

int t, x, a, b;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> x >> a >> b;
        int rabbit = 0;
        int drake = x;
        while (1) {
            if (drake - rabbit <= a) break;
            rabbit += (a * 2);
            drake += a + b;
        }
        int tmp = drake - rabbit;
        if (tmp > 0 && tmp <= a) {
            rabbit += (tmp * 2);
        }
        cout << rabbit << "\n";
    }

}