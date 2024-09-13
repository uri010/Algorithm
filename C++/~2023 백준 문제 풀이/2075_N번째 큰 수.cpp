//
// Created by 김유리 on 2023/07/01.
//
#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, x;
    priority_queue<int> pq;

    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> x;
        if (pq.size() < N) pq.push(-x);
        else if (!pq.empty() && (-pq.top()) < x) {
            pq.pop();
            pq.push(-x);
        }
    }

    cout << -pq.top();


}