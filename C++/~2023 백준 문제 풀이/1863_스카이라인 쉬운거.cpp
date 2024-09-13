//
// Created by 김유리 on 2023/12/07.
//
#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int n, x, cnt;
stack<int> s;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> arr[i];
    }

    s.push(0);
    for (int i = 0; i < n; i++) {
        if (s.top() < arr[i]) {
            cnt++;
            s.push(arr[i]);
        } else {
            while (!s.empty() && s.top() > arr[i]) {
                s.pop();
            }
            if (s.top() == arr[i]) continue;
            else if (s.top() < arr[i]) {
                s.push(arr[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
}