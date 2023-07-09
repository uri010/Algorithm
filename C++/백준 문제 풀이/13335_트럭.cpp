//
// Created by 김유리 on 2023/07/09.
//
#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int arr[1001];
int crossed[1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int weight = 0;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        while (true) {
            if (q.size() == w) {
                weight -= q.front();
                q.pop();
            }
            if (arr[i] + weight <= L) {
                break;
            }
            q.push(0);
            ans++;
        }
        q.push(arr[i]);
        weight += arr[i];
        ans++;
    }
    cout << ans + w;
}