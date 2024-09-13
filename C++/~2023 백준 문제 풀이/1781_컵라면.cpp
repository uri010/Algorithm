//
// Created by 김유리 on 2024/03/26.
//
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    vector<pair<int, int>> v(N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        if (pq.size() < v[i].first) {
            pq.push(v[i].second);
        } else {
            if (pq.top() < v[i].second) {
                pq.pop();
                pq.push(v[i].second);
            }
        }
    }

    int sum = 0;
    while( !pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}
