//
// Created by 김유리 on 2023/07/14.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, x;
vector<int> v;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    while (N--) {
        cin >> x;
        v.push_back(x);
    }

    stack<int> s;
    for (int i = v.size() - 1; i >= 0; i--) {
        int val = v[i];

        while (!s.empty() && s.top() <= val)
            s.pop();

        if (!s.empty() && s.top() > val)
            v[i] = s.top();
        else v[i] = -1;
        s.push(val);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


}