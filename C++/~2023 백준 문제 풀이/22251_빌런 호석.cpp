//
// Created by 김유리 on 2023/12/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, K, P, X;
int num[] = {0b1111110,
             0b0110000,
             0b1101101,
             0b1111001,
             0b0110011,
             0b1011011,
             0b1011111,
             0b1110000,
             0b1111111,
             0b1111011};
int arr[10][10] = {0}; // i와 j의 다른 bit 수
string str;

//DFS
int Solve(int depth, int cnt) {
    if (depth >= str.length()) {
        if (stoi(str) == X) return 0;
        if (stoi(str) <= N && stoi(str) >= 1) return 1;
        return 0;
    }

    int sum = 0;
    int cur = str[depth] - '0';
    for (int i = 0; i < 10; i++) {
        if ((cur != i) && (arr[cur][i] <= cnt)) {
            str[depth] = i + '0';
            sum += Solve(depth + 1, cnt - arr[cur][i]);
            str[depth] = cur + '0';
        }
        if (cur == i) sum += Solve(depth + 1, cnt);
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K >> P >> X;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int k = num[i] ^ num[j];
            while (k != 0) {
                if (k & 1) arr[i][j]++;
                k >>= 1;
            }
        }
    }

    str = to_string(X);
    while (str.length() < K) str.insert(str.begin(), '0');
    cout << Solve(0, P);
}