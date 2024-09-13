//
// Created by 김유리 on 2023/07/25.
//
#include <iostream>

using namespace std;

int N, K;
int arr[11];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        while (arr[i] <= K) {
            K -= arr[i];
            cnt++;
        }
    }
    cout << cnt;

}