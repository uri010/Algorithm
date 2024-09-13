//
// Created by 김유리 on 2023/07/09.
//
#include <iostream>
#include <stack>

using namespace std;
int N;
int arr[1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    stack<int> st;
    int cnt = 1;
    int flag = 0;
    for (int i = 0; i < N; i++) {
        while (true) {
            if (!st.empty() && st.top() == cnt) {
                cnt++;
                st.pop();
            } else {
                break;
            }
        }

        if (arr[i] == cnt)
            cnt++;
        else if (st.empty())
            st.push(arr[i]);
        else {
            if (st.top() > arr[i]) {
                st.push(arr[i]);
            } else {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) cout << "Sad";
    else cout << "Nice";
}
