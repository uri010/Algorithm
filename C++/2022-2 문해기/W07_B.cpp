//
// Created by 김유리 on 2022/11/02.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
string s;
int list[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            list[i] = s[i] - '0';
        }
        int max_length = 0;
        for (int i = 0; i < s.size(); i++) {
            int male = 0;
            int female = 0;
            for (int j = i; j < s.size(); j++) {
                if (list[j] == 0) {
                    male++;
                }
                else {
                    female++;
                }
                if (male == female) {
                    max_length = max(j - i + 1, max_length);
                }
            }
        }
        cout << max_length << "\n";

    }
}