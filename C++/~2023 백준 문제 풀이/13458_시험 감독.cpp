//
// Created by 김유리 on 2023/07/02.
//
#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, B, C;
    long long ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        arr[i] -= B;
        ans += 1;
        if (arr[i] <= 0) continue;
        if (arr[i] % C == 0) {
            ans += arr[i] / C;
        } else {
            ans += arr[i] / C + 1;
        }
    }
    cout << ans;
}
