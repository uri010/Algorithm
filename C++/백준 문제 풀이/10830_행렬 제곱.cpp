//
// Created by 김유리 on 2023/08/01.
//
#include <iostream>
#include <math.h>

using namespace std;

int N;
long long arr[6][6];
long long tmp[6][6];
long long ans[6][6];
long long B;

void multipleMatrix(long long a[6][6], long long b[6][6]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (a[i][k] * b[k][j]);
            }
            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        ans[i][i] = 1;
    }
    while (B > 0) {
        if (B % 2 == 1) {
            multipleMatrix(ans, arr);
        }
        multipleMatrix(arr, arr);
        B /= 2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}