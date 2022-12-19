//
// Created by 김유리 on 2022/11/02.
//
#include <stack>
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
        stack<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                q.push(s[i] - '0');
            }
            else {
                int n2 = q.top();
                q.pop();
                int n1 = q.top();
                q.pop();
                if (s[i] == '+') {
                    q.push(n1 + n2);
                }
                else if (s[i] == '-') {
                    q.push(n1 - n2);
                }
                else if (s[i] == '*') {
                    q.push(n1 * n2);
                }
            }
        }
        if (!q.empty()) {
            cout << q.top() << "\n";
            q.pop();
        }
    }
}