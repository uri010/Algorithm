//
// Created by 김유리 on 2022/07/18.
//
#include <iostream>
#include <cmath>

using namespace std;
int n;
int arr[1001];
int dp[1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i < n; i++){
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans;


}