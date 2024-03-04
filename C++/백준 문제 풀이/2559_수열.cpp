//
// Created by 김유리 on 2024/03/04.
//
#include <iostream>
#include <algorithm>

int N, K;
int S[100001];
int arr[100001];

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        S[i] = S[i - 1] + arr[i];
    }

    int maxNum = -100000001;
    for (int i = K; i <= N; i++) {
        maxNum = max(maxNum, S[i] - S[i - K]);
    }
    cout << maxNum;
}