//
// Created by 김유리 on 2023/07/15.
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

    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++) {
        int val = v[i];

        while (!s.empty() && s.top().first <= val)
            s.pop();

        if (!s.empty() && s.top().first > val)
            v[i] = s.top().second;
        else v[i] = 0;
        s.push({val, i+1});
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


}