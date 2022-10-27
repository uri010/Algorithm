//
// Created by 김유리 on 2022/10/27.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int idx = 1;
    while (true) {
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                st.push('{');
            } else if (s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    st.push('}');
                }
            } else {
                return 0;
            }
        }
        vector<char> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == '}') {
                ans++;
                i--;
                if (v[i] == '{')
                    ans++;
            } else if (v[i] == '{') {
                i--;
                if (v[i] == '{')
                    ans++;
            }
        }
        cout << idx << ". " << ans << "\n";
        idx++;
    }

}