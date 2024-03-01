//
// Created by 김유리 on 2024/03/01.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string str;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str.size() % 2 == 1) continue;

        stack<char> s;
        for (int j = 0; j < str.size(); j++) {
            if (s.empty()) s.push(str[j]);
            else if (s.top() == str[j]) {
                s.pop();
            } else {
                s.push(str[j]);
            }
        }
        if (s.empty()) answer++;
    }
    cout << answer;
}