//
// Created by 김유리 on 2022/09/19.
//
#include <iostream>
#include <stack>

using namespace std;

int k, x, total;
stack<int> st;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> k;
    while (k--) {
        cin >> x;
        if (x == 0)
            st.pop();
        else
            st.push(x);
    }

    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    cout << total;

}