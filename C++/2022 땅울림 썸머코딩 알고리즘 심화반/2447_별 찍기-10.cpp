//
// Created by 김유리 on 2022/08/17.
//
#include <iostream>

using namespace std;

int n;

void Solve(int i, int j, int size) {
    if (size == 1)
        cout << "*";
    else if ((i / (size / 3)) % 3 == 1 && (j / (size / 3)) % 3 == 1)
        cout << " ";
    else
        Solve(i, j, size / 3);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Solve(i, j, n);
        }
        cout << "\n";
    }
}