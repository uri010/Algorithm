//
// Created by 김유리 on 2022/09/05.
//
#include <iostream>

using namespace std;

int t;
string s;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0;
        int c_cnt = 0;
        int jump = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'C')
                c_cnt++;
            else {
                if (c_cnt == 0) {
                    ans = max(ans, 2 * jump);
                    jump = 0;
                } else {
                    jump++;
                    if (--c_cnt == 0)
                        ans = max(ans, 2 * jump);
                }
            }
        }
        if (c_cnt == 0) ans = max(ans, 2 * jump);

        int t_cnt = 0;
        jump = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                t_cnt++;
            } else {
                if (t_cnt == 0) {
                    ans = max(ans, 2 * jump);
                    jump = 0;
                } else {
                    jump++;
                    if (--t_cnt == 0)
                        ans = max(ans, 2 * jump);
                }
            }
        }
        if (t_cnt == 0) ans = max(ans, 2 * jump);

        cout << ans << "\n";
    }
    return 0;
}