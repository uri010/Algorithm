//
// Created by 김유리 on 2022/07/19.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long dp[100001];
long long dp2[100001];
long long arr[100001];
int n;
long long maxInt;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
        dp2[i] = arr[i];
    }
    maxInt = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
        maxInt = max(maxInt, dp[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        dp2[i] = max(dp2[i], dp2[i + 1] + arr[i]);
        maxInt = max(maxInt, dp2[i]);
    }
    maxInt = max(maxInt, dp2[n-1]);
    maxInt = max(maxInt, dp2[1]);
    for (int i = 1; i < n; i++) {
        long long tmp = dp[i - 1] + dp2[i + 1];
        if (tmp > maxInt) maxInt = tmp;
    }
    cout << maxInt;

}