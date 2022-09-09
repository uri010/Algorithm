//
// Created by 김유리 on 2022/09/09.
//
#include <iostream>

using namespace std;

int t, m, n, l;
string alpha[27];
string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> alpha[i];
        }
        cin >> l;
        cin >> s;
        for (int i = 0; i < s.size(); i += n) {
            int max_length = 0;
            int index = -1;
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                string tmp = alpha[j];
                for (int k = 0; k < n; k++) {
                    if (tmp[k] == s[i + k]) {
                        cnt++;
                    }
                }
                if( max_length < cnt) {
                    max_length = cnt;
                    index = j;
                }
            }
            char ans = index+'A';
            cout << ans;
        }
        cout << "\n";
    }

}