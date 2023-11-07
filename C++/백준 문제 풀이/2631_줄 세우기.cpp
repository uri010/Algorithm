//
// Created by 김유리 on 2023/11/07.
//
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[201];
int dp[201];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i=1; i <=N; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=1; i <=N; i++){
        dp[i] = 1;
        for(int j=1; j<=i; j++){
            if (arr[j] < arr[i] && dp[i] < dp[j] +1 ){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << N-ans;
}