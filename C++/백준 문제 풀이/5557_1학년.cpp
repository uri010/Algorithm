//
// Created by 김유리 on 2023/08/06.
//
#include <iostream>
#include <cstring>

using namespace std;

int N, ans;
int arr[101];
long long dp[101][21];

long long Solve(int i, int result) {
    if (i == 0 && result == arr[0]) return dp[i][result] = 1;
    if (i == 0 && result != arr[0]) return dp[i][result] == 0;

    if (dp[i][result] != -1)
        return dp[i][result];
    long long tmp = 0;
    if (result - arr[i] >= 0)
        tmp += Solve(i - 1, result - arr[i]);
    if (result + arr[i] <= 20)
        tmp += Solve(i - 1, result + arr[i]);
    return dp[i][result] = tmp;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> arr[i];
    }
    cin >> ans;
    memset(dp, -1, sizeof(dp));
    cout << Solve(N - 2, ans);
}