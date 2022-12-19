//
// Created by 김유리 on 2022/11/02.
//
#include<iostream>
#include<queue>

using namespace std;


#define MAXSTRING  1000

int dp[MAXSTRING + 1][MAXSTRING + 1];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string s1, s2;

    while (T--) {

        cin >> s1;
        cin >> s2;
        for (int s = 1; s < s1.size() + 1; s++) {
            dp[s][0] = s;
        }
        for (int s = 1; s < s2.size() + 1; s++) {
            dp[0][s] = s;
        }
        for (int s1Idx = 1; s1Idx < s1.size() + 1; s1Idx++) {
            for (int s2Idx = 1; s2Idx < s2.size() + 1; s2Idx++) {
                if (s1[s1Idx - 1] == s2[s2Idx - 1]) {
                    dp[s1Idx][s2Idx] = dp[s1Idx - 1][s2Idx - 1];
                } else {
                    dp[s1Idx][s2Idx] = min(dp[s1Idx - 1][s2Idx - 1] + 1,
                                           min(dp[s1Idx][s2Idx - 1] + 1, dp[s1Idx - 1][s2Idx] + 1));
                }
            }
        }
        cout << dp[s1.size()][s2.size()] << "\n";
    }
}