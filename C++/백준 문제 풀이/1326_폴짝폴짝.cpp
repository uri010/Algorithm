//
// Created by 김유리 on 2023/07/05.
//
#include <iostream>
#include <queue>
#define INF 1000000000

using namespace std;

int N, a, b;
int arr[10002];
int dist[10002];
priority_queue<pair<int, int>> q;

int Solve() {
    q.push({0, a});
    while (!q.empty()) {
        int cnt = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if (cur == b) return cnt;
        if( dist[cur] < cnt) continue;
        dist[cur] = cnt;

        int next = cur;
        int value = arr[cur];
        while (next + value <= N) {
            next += value;
            if( dist[next] < cnt+1) continue;
            q.push({-(cnt + 1), next});
        }
        next = cur;
        while (next - value >= 1) {
            next -= value;
            if( dist[next] < cnt+1) continue;
            q.push({-(cnt + 1), next});
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dist[i] = INF;
    }
    cin >> a >> b;
    cout << Solve();

}
/*
 * 5 5 2 2 1 2 1 5
 */