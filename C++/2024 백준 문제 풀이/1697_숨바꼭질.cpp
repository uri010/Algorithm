//
// Created by 김유리 on 2024. 9. 17..
//
#include <iostream>
#include <queue>

#define MAX 100000
using namespace std;

int N, K;
int arr[MAX + 1];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for(int i=0; i < MAX+1; i++){
        arr[i] = MAX;
    }
    queue<int> q;
    q.push(N);
    arr[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur + 1 <= MAX && arr[cur + 1] > arr[cur] + 1) {
            arr[cur + 1] = arr[cur] + 1;
            q.push(cur + 1);
        }
        if (cur - 1 >= 0 && arr[cur - 1] > arr[cur] + 1) {
            arr[cur - 1] = arr[cur] + 1;
            q.push(cur - 1);
        }
        if (cur * 2 <= MAX && arr[cur * 2] > arr[cur] + 1) {
            arr[cur * 2] = arr[cur] + 1;
            q.push(cur * 2);
        }
    }
    cout << arr[K];
}
