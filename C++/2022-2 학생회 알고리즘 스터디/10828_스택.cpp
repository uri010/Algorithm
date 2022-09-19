//
// Created by 김유리 on 2022/09/19.
//
#include <stack>
#include <iostream>

using namespace std;

string s;
int n, x;
stack<int> st;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            st.push(x);
        } else if (s == "pop") {
            if (st.empty())
                cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if (s == "size") {
            cout << st.size() << "\n";
        } else if (s == "empty") {
            if (st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (s == "top") {
            if (st.empty())
                cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
            }
        }
    }

}