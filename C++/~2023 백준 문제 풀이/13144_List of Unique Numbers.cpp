//
// Created by 김유리 on 2024/01/15.
//
#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[100001];
bool checked[100001];
long long cnt;
queue<int> q;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0, end = N - 1;
    while (start <= end) {
        if (!checked[arr[start]]) {
            checked[arr[start]] = true;
            q.push(arr[start]);
            start++;
        } else {
            cnt += (long)q.size();
            int removeNum = q.front();
            q.pop();
            checked[removeNum] = false;
        }
    }

    long remain = (long)q.size();
    cnt += remain * (remain + 1) / 2;
    cout << cnt;
}