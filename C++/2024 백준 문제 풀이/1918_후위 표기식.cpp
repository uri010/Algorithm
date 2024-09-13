//
// Created by 김유리 on 2024. 9. 14..
//
#include <iostream>
#include <stack>

using namespace std;

int prio(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
        else if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            int curPriority = prio(s[i]);
            while (!st.empty() && prio(st.top()) >= curPriority) {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
