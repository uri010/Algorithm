//
// Created by 김유리 on 2023/08/07.
//
#include <iostream>
#include <cstring>

using namespace std;

int T, N, P;
int arr[21];
int dp[10001];


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cin >> P;

        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = arr[i]; j <= P; j++) {
                dp[j] = dp[j] + dp[j - arr[i]];
            }
        }
        cout << dp[P] << "\n";
    }

}