//
// Created by 김유리 on 2023/07/28.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, strike, ball;
bool avail[1000];
vector<string> v;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    memset(avail, true, sizeof(avail));
    for (int i = 123; i <= 999; i++) {
        string str = to_string(i);
        if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2] || str[0] == '0' || str[1] == '0' || str[2] == '0')
            avail[i] = false;
    }
    cin >> N;
    string x;
    while (N--) {
        cin >> x >> strike >> ball;
        for (int i = 123; i <= 999; i++) {
            int st_cnt = 0;
            int ball_cnt = 0;
            if (!avail[i]) continue;
            string s = to_string(i);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k && x[j] == s[k]) st_cnt++;
                    if (j != k && x[j] == s[k]) ball_cnt++;
                }
            }
            if (st_cnt != strike || ball_cnt != ball) avail[i] = false;
        }
    }
    int ans = 0;
    for (int i = 123; i <= 999; i++) {
        if (avail[i]) ans++;
    }
    cout << ans;
}
