//
// Created by 김유리 on 2024/03/04.
//
#include <iostream>
#include <string>

using namespace std;

string s[64];

void Compression(int x, int y, int size) {
    char type = s[y][x];
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (type != s[i][j]) {
                size = size / 2;
                cout << '(';
                Compression(x, y, size);
                Compression(x + size, y, size);
                Compression(x, y + size, size);
                Compression(x + size, y + size, size);
                cout << ')';
                return;
            }
        }
    }
    cout << type;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    Compression(0, 0, N);
}