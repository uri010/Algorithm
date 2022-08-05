//
// Created by 김유리 on 2022/08/05.
//
#include <iostream>

using namespace std;

int m, n;
int map[1410];
int a, b, c;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = a; j < a + b; j++) {
            map[j] += 1;
        }
        for (int j = a + b; j < 2 * m - 1; j++) {
            map[j] += 2;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << map[m - i - 1] + 1 << " ";
        for (int j = m; j < 2 * m - 1; j++) {
            cout << map[j] + 1 << " ";
        }
        cout << "\n";
    }


}